(function(e){function t(t){for(var n,r,o=t[0],h=t[1],c=t[2],f=0,u=[];f<o.length;f++)r=o[f],Object.prototype.hasOwnProperty.call(s,r)&&s[r]&&u.push(s[r][0]),s[r]=0;for(n in h)Object.prototype.hasOwnProperty.call(h,n)&&(e[n]=h[n]);l&&l(t);while(u.length)u.shift()();return i.push.apply(i,c||[]),a()}function a(){for(var e,t=0;t<i.length;t++){for(var a=i[t],n=!0,o=1;o<a.length;o++){var h=a[o];0!==s[h]&&(n=!1)}n&&(i.splice(t--,1),e=r(r.s=a[0]))}return e}var n={},s={mqtt:0},i=[];function r(t){if(n[t])return n[t].exports;var a=n[t]={i:t,l:!1,exports:{}};return e[t].call(a.exports,a,a.exports,r),a.l=!0,a.exports}r.m=e,r.c=n,r.d=function(e,t,a){r.o(e,t)||Object.defineProperty(e,t,{enumerable:!0,get:a})},r.r=function(e){"undefined"!==typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(e,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(e,"__esModule",{value:!0})},r.t=function(e,t){if(1&t&&(e=r(e)),8&t)return e;if(4&t&&"object"===typeof e&&e&&e.__esModule)return e;var a=Object.create(null);if(r.r(a),Object.defineProperty(a,"default",{enumerable:!0,value:e}),2&t&&"string"!=typeof e)for(var n in e)r.d(a,n,function(t){return e[t]}.bind(null,n));return a},r.n=function(e){var t=e&&e.__esModule?function(){return e["default"]}:function(){return e};return r.d(t,"a",t),t},r.o=function(e,t){return Object.prototype.hasOwnProperty.call(e,t)},r.p="";var o=window["webpackJsonp"]=window["webpackJsonp"]||[],h=o.push.bind(o);o.push=t,o=o.slice();for(var c=0;c<o.length;c++)t(o[c]);var l=h;i.push([3,"chunk-vendors","chunk-common"]),a()})({"26e3":function(e,t,a){"use strict";var n=a("ed4d"),s=a.n(n);s.a},3:function(e,t,a){e.exports=a("cee3")},b445:function(e,t,a){"use strict";var n=a("c10f"),s=a.n(n);s.a},c10f:function(e,t,a){},cee3:function(e,t,a){"use strict";a.r(t);a("e260"),a("e6cf"),a("cca6"),a("a79d");var n,s=a("2b0e"),i=function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("chats-wrapper",{attrs:{chat:e.chatData,"show-chats":e.showChats,"no-live-tips":e.guideText,"max-input-character":e.maxInputCharactor,"disable-input":e.isFacebook||!e.showChats||!e.isLiving||e.isPlatformClose},on:{"live-init":e.handleLiveInit,"live-end":e.handleLiveEnd,"live-platform-close":e.handlePlatformClose,"chat-receive":e.handleChat,"handle-send":e.handleSend,"handle-show-tab":e.showFacebookToast,"handle-permission":e.handlePermission},scopedSlots:e._u([{key:"chat",fn:function(t){var n=t.item;return[a(e.temp,{tag:"component",attrs:{data:n,"no-channel-image":""}})]}}])})},r=[],o=(a("a4d3"),a("e01a"),a("7db0"),a("4160"),a("caad"),a("fb6a"),a("b0c0"),a("d3b7"),a("ac1f"),a("2532"),a("3ca3"),a("5319"),a("841c"),a("159b"),a("ddb0"),a("2b3d"),a("de36")),h=a("2f14"),c=a("eb9e"),l=a("7ea6"),f=a("7127"),u=a("487d"),d=a("d609"),m=a("65e1"),p=function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("transition",{attrs:{name:"fade"}},[e.show?a("div",{ref:"toast",staticClass:"toast-rtmp",style:e.position},[a("div",{staticClass:"toast-rtmp-container"},[a("btn-close",{staticClass:"toast-btn-close",attrs:{"is-small":""},on:{click:e.handleToastClose}}),a("span",{domProps:{innerHTML:e._s(e.content)}})],1)]):e._e()])},v=[],b=a("4d06"),g={name:"prismToast",components:{BtnClose:b["a"]},data:function(){return{show:!1,position:"",content:""}},methods:{handleToastClose:function(){this.show=!1}},mounted:function(){var e=this;this.show=!0,setTimeout((function(){e.handleToastClose()}),5e3)}},C=g,P=(a("b445"),a("2877")),w=Object(P["a"])(C,p,v,!1,null,null,null),O=w.exports,T=s["a"].extend(O),S=function(){n=new T({el:document.createElement("div")}),document.body.appendChild(n.$el)},y=function(e){var t=arguments.length>1&&void 0!==arguments[1]?arguments[1]:{};e&&(t.content=e,S(),A(n.$data,t),n.show=!0)};function A(e,t){if(t){for(var a in t)if(t.hasOwnProperty(a)){var n=t[a];void 0!==n&&(e[a]=n)}return e}}var L=y,E=a("d068"),j={name:"prismMqtt",mixins:[f["a"]],components:{ChatsWrapper:u["a"],TemplateNormal:d["a"],TemplateAfreeca:m["a"]},data:function(){return{channel:"",isLiving:!1,showChats:!1,chatData:[],prismParams:{},pollTime:5e3,bufferManager:null,maxInputCharactor:o["MAX_INPUT_CHARACTER_AFREECATV"],isPlatformClose:!1,isShowFbToast:!1}},watch:{chatData:function(e){this.isLiving&&localStorage.setItem(this.channel,JSON.stringify({videoSeq:this.prismParams.videoSeq,list:e.slice(0,o["MAX_LOCAL_CACHED_CHAT_COUNT"])}))}},computed:{isFacebook:function(){return this.channel===o["CHANNEL"].FACEBOOK},isAfreecaTV:function(){return this.channel===o["CHANNEL"].AFREECATV},channelName:function(){return this.channel&&o["CHANNEL_NAME"][this.channel]},guideText:function(){return this.isLiving?this.$i18n["forbidden"+this.channel]:this.$i18n.noLiveNaver.replace("${platform}",this.channelName)},temp:function(){return this.isAfreecaTV?m["a"]:d["a"]}},methods:{handlePlatformClose:function(e){e.platform===this.channel&&(Object(E["a"])({message:this.channel+"Chat: This chat platform is disabled"}),this.isPlatformClose=!0)},readStorage:function(e){Object(E["a"])({message:this.channel+"Chat: read chat storage"});var t=localStorage.getItem(this.channel)||null;return"string"===typeof t&&(t=JSON.parse(t)),localStorage.removeItem(this.channel),t&&t.videoSeq===e?(Object(E["a"])({message:this.channel+"Chat: read chat storage success, storage chat length".concat(t.list.length)}),t.list.forEach((function(e){return e.id=Symbol()})),t.list):(Object(E["a"])({message:this.channel+"Chat: read chat storage but no chat data"}),!1)},handleLiveInit:function(e){var t=this;if(!this.isLiving&&(this.clearPage(),e&&e.platforms&&(this.prismParams=e.platforms.find((function(e){return e.name===t.channel})),this.prismParams.videoSeq=e.videoSeq,this.prismParams&&(Object(E["a"])({message:this.channel+"Chat: Get the initialization data"}),this.isLiving=!0,this.bufferManager=new l["a"](this.chatData,{pollTime:this.pollTime}),this.prismParams.isPrivate||(this.showChats=!0,this.showFacebookToast({platform:this.channel})),this.prismParams.videoSeq)))){var a=this.readStorage(this.prismParams.videoSeq);a&&(this.chatData=a)}},showFacebookToast:function(e){this.isLiving&&e.platform===this.channel&&!this.isShowFbToast&&this.isFacebook&&!this.prismParams.isPrivate&&(L(this.$i18n.facebookNoSend,{position:{bottom:"60px"}}),this.isShowFbToast=!0)},handleLiveEnd:function(){Object(E["a"])({message:this.channel+"Chat: The live broadcast is over"}),this.isLiving=!1},handleChat:function(e){var t=this;if(this.isLiving){var a=[];e.forEach((function(e){if(e.livePlatform===t.channel)if(t.isFacebook&&t.prismParams.isPrivate&&t.handlePermission({platform:o["CHANNEL"].FACEBOOK,isPrivate:!1}),e.id=Symbol(),e.timeago=Object(c["a"])(e.publishedAt,t.$lang),t.isAfreecaTV){var n=t.handleAfreecatvChat(e,t.prismParams.userId);n&&a.push(n)}else if(t.isFacebook){var s=e.rawMessage=Object(h["a"])(e.rawMessage);e._isSelf=s.from.id&&+s.from.id===+t.prismParams.userId;var i=e.rawMessage.attachment||{};(e.message||"animated_image_share"===i.type&&i.media.source||"sticker"===i.type)&&a.push(e)}else e._isSelf=e.author.isChatOwner,a.push(e)})),this.bufferManager.push(a),a.length&&Object(E["a"])({message:this.channel+"Chat: Receive new chat"})}},handleSend:function(e){Object(E["a"])({message:this.channel+"Chat: send chat"}),window.sendToPrism(JSON.stringify({type:"send",data:{platform:this.channel,message:e}}))},handlePermission:function(e){this.isLiving&&this.channel===e.platform&&(Object(E["a"])({message:this.channel+"Chat: Update chat permission data"}),e.isPrivate&&!this.prismParams.isPrivate&&this.isFacebook&&L(this.$i18n.forbiddenFACEBOOK,{position:{top:"10px"}}),this.prismParams.isPrivate=e.isPrivate,e.isPrivate?this.isAfreecaTV&&(this.showChats=!1):(this.showChats=!0,this.showFacebookToast({platform:this.channel})))},clearPage:function(){this.isPlatformClose=!1,this.isLiving=!1,this.showChats=!1,this.chatData=[],this.prismParams={},this.isShowFbToast=!1,this.clearBufferManager()},clearBufferManager:function(){this.bufferManager&&(this.bufferManager.clearTimer(),this.bufferManager=null)}},created:function(){var e=new URLSearchParams(document.location.search).get("platform")||"";this.channel=e.toLocaleUpperCase(),[o["CHANNEL"].FACEBOOK,o["CHANNEL"].AFREECATV].includes(this.channel)||Object(E["a"])({message:this.channel+"Chat: Did not get the correct Name on the URL"},"error")},mounted:function(){Object(E["a"])({message:this.channel+"Chat: The chat page loads successfully"})},beforeDestroy:function(){Object(E["a"])({message:this.channel+"Chat: The chat page is closed"}),this.clearBufferManager()}},_=j,N=(a("26e3"),Object(P["a"])(_,i,r,!1,null,null,null)),F=N.exports;a("21af");a("58d1").default(s["a"]),a("8e7d").default(s["a"]),s["a"].config.productionTip=!1,new s["a"]({render:function(e){return e(F)}}).$mount("#app")},ed4d:function(e,t,a){}});