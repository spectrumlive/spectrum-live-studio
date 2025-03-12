/******************************************************************************
 Copyright (C) 2025 by Nanusorn Photpipat (nanusorn@photpipat.com)

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/

#include "SPTAPIServices.hpp"

class CurlWrite
{
public:
   static size_t writeData(void* ptr, size_t size, size_t nmemb, void* buffer)
   {
      Q_UNUSED(size);
      ((std::string*) buffer)->append((char*) ptr, nmemb);
      return nmemb;
   }
};

QJsonObject SPTAPIServices::getUserInfo() {
   CURL *curl = curl_easy_init();
   
   if (!curl) {
      qDebug() << "curl init failed";
      return ObjectFromString(QString("{\"success\": false, \"description\": %1}").arg("curl init failed"));
   }
   
   // set options
   std::string out;
   curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);
   curl_easy_setopt(curl, CURLOPT_URL, "https://beta.spectrumlive.xyz/api/auth/me");
   curl_easy_setopt(curl, CURLOPT_XOAUTH2_BEARER, m_strToken.toStdString().c_str());
   curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BEARER);
   curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite::writeData);
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, &out);
   
   // callint action
   CURLcode result = curl_easy_perform(curl);
   if (result != CURLE_OK) {
      return ObjectFromString(QString("{\"success\": false, \"description\": %1").arg(curl_easy_strerror(result)));
   }
   
   curl_easy_cleanup(curl);
   
   return ObjectFromString(out.c_str());
}

QJsonObject SPTAPIServices::ObjectFromString(const QString& in) {
   QJsonObject obj;
   QJsonDocument doc = QJsonDocument::fromJson(in.toUtf8());
   
      // check validity of the document
   if(!doc.isNull()) {
      if(doc.isObject()) {
         obj = doc.object();
      }
      else  {
         qDebug() << "Document is not an object";
      }
   }
   else {
      qDebug() << "Invalid JSON...\n" << in;
   }
   return obj;
}
