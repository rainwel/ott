//
//  gEnum.h
//  awesomeott
//
//  Created by Rui Wei on 10/17/14.
//
//

#ifndef __awesomeott__gEnum__
#define __awesomeott__gEnum__

namespace ottenum {

enum KEY_CODE {
  KEY_UP = 1999,
  KEY_DOWN = 2000,
  KEY_LEFT = 2001,
  KEY_RIGHT = 2002,
  KEY_OK = 2003,
  KEY_MENU = 2004,
  KEY_BACK = 2005,
  KEY_ZERO = 2200
};

enum NextActionType {
  NONE,
  PUSH_FRAME,
  POP_FRAME,
  PUSH_FRAME_STILL,
  PUSH_FRAME_ZOOMIN,
  PUSH_FRAME_FROMRIGHT,
  PUSH_DIRECT_URL,
  SHOW_LOADING,
  SHOW_LOADING_NOREQUEST,
  SHOW_LOADING_FROMRIGHT,
  SHOW_DIALOG,
  CLOSE_DIALOG,
  PLAY_VIDEO,
  SHOW_POPUP
};

enum FrameType { FRAME, DIALOG, LOADING, VIDEO, FRAME_LEFT };

enum LocalHomeType { LocalHomeType_Preset, LocalHomeType_Cache };

enum TAG_FRAME {
  TAG_FRAME_OFFLINE = 100,
  TAG_FRAME_SPLASH,
  TAG_FRAME_PROGRESS,
  TAG_FRAME_DETAIL,
  TAG_FRAME_HOME,
  TAG_FRAME_APPMGMT,
  TAG_FRAME_SEARCH,
  TAG_FRAME_MIAPPLIST,
  TAG_FRAME_WHTAPPLIST,
  TAG_FRAME_RECMDAPPS,
  TAG_FRAME_APPLIST,
  TAG_FRAME_SETTINGDETAIL,
  TAG_FRAME_CONFIG,
  TAG_FRAME_SCROLL,
  TAG_FRAME_RankList,
  TAG_FRAME_LIST,
  TAG_FRAME_FILTER,
  TAG_FRAME_HISTORY,
  TAG_FRAME_FAVORITE
};

enum TAG_WIDGET {
  TAG_WIDGET_ALPHA = 400,
  TAG_WIDGET_BOTTOMMENU,
  TAG_WIDGET_LOGO,
  TAG_WIDGET_BACKGROUND,
  TAG_WIDGET_BACKGROUND_DEFAULT,
  TAG_WIDGET_LINE,
  TAG_WIDGET_IMAGE,
  TAG_WIDGET_TITLE,
  TAG_WIDGET_SUBTITLE,
  TAG_WIDGET_TIP,
  TAG_WIDGET_LOADING,
  TAG_WIDGET_PROGRESS,
  TAG_WIDGET_PROGRESS_BG,
  TAG_WIDGET_SCREENSHOT_LEFT,
  TAG_WIDGET_SCREENSHOT_RIGHT,
  TAG_WIDGET_NOTICETOPBAR,
  TAG_WIDGET_NOTICESIDEBAR,
  TAG_WIDGET_TIMEWIFIPAD,
  TAG_WIDGET_CLOSE,
  TAG_WIDGET_EPISODEBAR,
  TAG_WIDGET_ARROW,
  TAG_WIDGET_BUTTON = 700,
  TAG_WIDGET_BOX = 800,
};

enum OTT_STYLE {
  OTT_STYLE_WHTUI = 10, //万花筒风格UI
  OTT_STYLE_MIUI,       //小米风格UI
  OTT_STYLE_TJUI,       //泰捷风格UI
  OTT_STYLE_TILEUI      //平铺风格UI
};

enum StrKey {
  StrKey_Alpha = 2000,      // Begin
  StrKey_Background,        // Home Page Background
  StrKey_Logo,              // Home Page Logo on the Left-Top
  StrKey_Placeholder,       // PlaceHolder on the list
  StrKey_SplashBackground,  // Splash Page Background
  StrKey_SSID,              // Network SSID
  StrKey_AlbumName,         // Wanhuatong Album Display Name
  StrKey_AlbumPackage,      // Wanhuatong Album Package Name
  StrKey_AlbumIcon,         // Wanhuatong Album Icon
  StrKey_CurrentPageId,     // Current Page Id
  StrKey_LastVariety,       // Last Played Variety Episode
  StrKey_AllFavorApps,      // All the favor apps
  StrKey_AllSysApps,        // All System Apps
  StrKey_AllGrantApps,      // All Granted Apps
  StrKey_BDQRTip,           // Baiduyun QR Code tip
  StrKey_BDLoginedTip,      // Baiduyun Logined Tip
  StrKey_BDUnLoginedTip,    // Baiduyun unlogined Tip
  StrKey_BDDownloadUrl,     // Baiduyun download url
  StrKey_WHTChannel,        // Wanhuatong Channel / Key
  StrKey_NavigateKey,       // Navigation Key
  StrKey_HardwareModel,     // Hardware Model
  StrKey_FileBrowser,       // File Browser
  StrKey_DealerLogo,        // Dealer Logo on the right-bottom of Splash Page
  StrKey_DealerBackground,  // Dealer background of Splash Page
  StrKey_ImgAboutUS,        // About US Image
  StrKey_WritablePath,      // Writable Path
  StrKey_CurrentAppName,    // Current App Name
  StrKey_CurrentAppPackage, // Current App Package Name
  StrKey_AppVersionName, // App Version Name. eg: 1.2804->1.2804; 1.9.5->1.9.5
  StrKey_AppVersionNameExt, // App Version Name Ext. eg: 1.2804->1.2804;
  // 1.9.5->1.950
  StrKey_AppFreePackages, // All the pacakge name of AppFreeBoxes.
  StrKey_PackageName,     // Package Name
  StrKey_SettingPackage,  // Setting Package Name
  StrKey_UUID,            // Device UUID
  StrKey_Uninstalled,     // Uninstalled Package Name
  StrKey_Disclaimer_PKG,  // Disclaimer, check the package
  StrKey_Disclaimer_NAME, // Disclaimer, package name
  StrKey_Disclaimer_URL,  // Disclaimer, download URL
  StrKey_Disclaimer_TXT,  // Disclaimer, text
  StrKey_Zorro            // End
};

enum BoolKey {
  BoolKey_Alpha,              // Begin
  BoolKey_PlayPreinstalled,   // if installed, return true.
  BoolKey_WifiFrameRunning,   // Wifi Frame is running or not?
  BoolKey_HideHomePage,       // Show Home Frame or Only show setting and apps?
  BoolKey_BDQRLogined,        // Baiduyun QR Logined
  BoolKey_BDTokenChanged,     // Baiduyun Token Changed
  BoolKey_MuteKeytone,        // Mute the key-tone by clicking the key
  BoolKey_TouchEnabled,       // Enabled Touch Event
  BoolKey_SlientQueueRunning, // SlientQueue is Running
  BoolKey_ShowQuit,           // enable quit and show it
  BoolKey_ShowRemoteInstall,  // enable remote install and show it
  BoolKey_ShowHomeLogo,       // enable home logo and show it
  BoolKey_ShowRecommendApp,   // enable Recommend App and show it
  BoolKey_ShowUninstall,      // enable uninstall App and show it
  BoolKey_ShowScreenSaver,    // enable screen saver and show it
  BoolKey_ShowLivePage,       // show live page 直播
  BoolKey_ShowAppPage,        // show app page 应用
  BoolKey_ShowSettingPage,    // show setting page 设置
  BoolKey_ShowUpgradePrompt,  // show upgrade prompt
  BoolKey_ShowReflection,     // Show reflection
  BoolKey_ShowMIShadow,       // Show MIUI Home Shadow
  BoolKey_ResetHomePage,      // reset home page
  BoolKey_MiDetailPage,       // Use Mi Detail Page
  BoolKey_MiVerticalList,     // Use Mi Vertical List
  BoolKey_MiVerticalListFixedMenu, // Use Mi Vertical List with the left menu
  // fixed on the left
  BoolKey_ShowFlyFrame,     // Show fly frame
  BoolKey_StayonBackground, // This App will stay running on the background,
  // when other app is running.
  BoolKey_ToRefreshApps,     // Need to refresh apps
  BoolKey_ToRefreshChannels, // Need to refresh channels
  BoolKey_ToRefreshHome,     // Need to refresh home page
  BoolKey_UpgradeDownloaded, // Upgrade Package was downloaded.
  BoolKey_WHTVideo,          // Is wanhuatong video? 万花筒视频？
  BoolKey_TargetForIOS,      // Is running on iOS platform? iOS 平台？
  BoolKey_ShowHiddenApps,    // show the hidden apps
  BoolKey_FinalServerLoaded, // Does it try the final servers?
  BoolKey_ShowHomeUpgradeIndicator,
  // //若收藏有更新。在首页历史收藏icon上显示更新
  BoolKey_ShowFavUpgradeIndicator, //若收藏有更新。在追剧收藏菜单上显示更新
  BoolKey_Zorro                    // End
};

enum IntKey {
  IntKey_FreeMemoryMB,   // Available Memory Size
  IntKey_TotalMemoryMB,  // Total Memory Size
  IntKey_LastEpisode,    // Last Played Episode
  IntKey_FavoriteNumber, // Favorite Number
  IntKey_WHTAlbumAppId,  // Wanhuatong album App ID
  IntKey_CocosState,     // cocos2dx state, is running or pausing?
  IntKey_AutoStart,      // Auto Start it by turning on the TV box
  IntKey_AppVersionCode  // App VersionCode
};
}
#endif /* defined(__awesomeott__gEnum__) */
