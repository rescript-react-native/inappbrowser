type authResult = {
  [@bs.as "type"]
  resultType: [ | `cancel | `dismiss | `success],
  url: option(string),
};

type browserResult = {
  [@bs.as "type"]
  resultType: [ | `cancel | `dismiss],
};

type iosOptions;
[@bs.obj]
external iosOptions:
  (
    ~dismissButtonStyle: [@bs.string] [
                           | [@bs.as "done"] `doneButton
                           | [@bs.as "close"] `closeButton
                           | [@bs.as "cancel"] `cancelButton
                         ]
                           =?,
    ~preferredBarTintColor: string=?,
    ~preferredControlTintColor: string=?,
    ~readerMode: bool=?,
    ~animated: bool=?,
    ~modalPresentationStyle: [
                               | `automatic
                               | `fullScreen
                               | `pageSheet
                               | `formSheet
                               | `currentContext
                               | `ustom
                               | `overFullScreen
                               | `overCurrentContext
                               | `popover
                               | `none
                             ]
                               =?,
    ~modalTransitionStyle: [
                             | `coverVertical
                             | `flipHorizontal
                             | `crossDissolve
                             | `partialCurl
                           ]
                             =?,
    ~modalEnabled: bool=?,
    ~enableBarCollapsing: bool=?,
    ~ephemeralWebSession: bool=?,
    unit
  ) =>
  iosOptions;

type androidAnimationOptions = {
  startEnter: string,
  startExit: string,
  endEnter: string,
  endExit: string,
};

type androidOptions;
[@bs.obj]
external androidOptions:
  (
    ~showTitle: bool=?,
    ~toolbarColor: string=?,
    ~secondaryToolbarColor: string=?,
    ~enableUrlBarHiding: bool=?,
    ~enableDefaultShare: bool=?,
    ~forceCloseOnRedirection: bool=?,
    ~animations: androidAnimationOptions=?,
    ~headers: Js.t('a)=?,
    ~hasBackButton: bool=?,
    ~browserPackage: string=?,
    ~showInRecents: bool=?,
    unit
  ) =>
  androidOptions;

[@bs.module "react-native-inappbrowser-reborn"] [@bs.scope "InAppBrowser"]
external isAvailable: unit => Js.Promise.t(bool) = "isAvailable";

[@bs.module "react-native-inappbrowser-reborn"] [@bs.scope "InAppBrowser"]
external openBrowserIos: (string, iosOptions) => Js.Promise.t(browserResult) =
  "open";

[@bs.module "react-native-inappbrowser-reborn"] [@bs.scope "InAppBrowser"]
external openBrowserAndroid:
  (string, androidOptions) => Js.Promise.t(browserResult) =
  "open";

[@bs.module "react-native-inappbrowser-reborn"] [@bs.scope "InAppBrowser"]
external close: unit => unit = "close";

[@bs.module "react-native-inappbrowser-reborn"] [@bs.scope "InAppBrowser"]
external openAuthIos: (string, string, iosOptions) => Js.Promise.t(authResult) =
  "openAuth";

[@bs.module "react-native-inappbrowser-reborn"] [@bs.scope "InAppBrowser"]
external openAuthAndroid:
  (string, string, androidOptions) => Js.Promise.t(authResult) =
  "openAuth";

[@bs.module "react-native-inappbrowser-reborn"] [@bs.scope "InAppBrowser"]
external closeAuth: unit => unit = "closeAuth";
