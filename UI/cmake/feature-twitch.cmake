if(TWITCH_CLIENTID AND TWITCH_HASH MATCHES "^(0|[a-fA-F0-9]+)$" AND TARGET OBS::browser-panels)
  target_sources(spectrum-studio PRIVATE auth-twitch.cpp auth-twitch.hpp)
  target_enable_feature(spectrum-studio "Twitch API connection" TWITCH_ENABLED)
else()
  target_disable_feature(spectrum-studio "Twitch API connection")
  set(TWITCH_CLIENTID "")
  set(TWITCH_HASH "0")
endif()
