# `@reason-react-native/inappbrowser`

[![Chat](https://img.shields.io/discord/235176658175262720.svg?logo=discord&colorb=blue)](https://reason-react-native.github.io/discord/)

[ReScript](https://rescript-lang.org) / [Reason](https://reasonml.github.io) bindings for
[`react-native-inappbrowser-reborn`](https://github.com/proyecto26/react-native-inappbrowser).

Exposed as `ReactNativeInAppBrowser` module.

`@reason-react-native/inappbrowser` X.y.\* means it's compatible with
`react-native-inappbrowser-reborn` X.y.\*

## Installation

When
[`react-native-inappbrowser-reborn`](https://github.com/proyecto26/react-native-inappbrowser)
is properly installed & configured by following their installation instructions,
you can install the bindings:

```console
npm install @reason-react-native/inappbrowser
# or
yarn add @reason-react-native/inappbrowser
```

`@reason-react-native/inappbrowser` should be added to `bs-dependencies` in your
`bsconfig.json`:

```diff
{
  //...
  "bs-dependencies": [
    "reason-react",
    "reason-react-native",
    // ...
+    "@reason-react-native/inappbrowser"
  ],
  //...
}
```

## Usage

```reason
open Js.Promise;
open ReactNativeInAppBrowser;

let opts = iosOptions(~preferredBarTintColor="#ff0000", ());
openBrowser("https://rescript-lang.org", `IosOptions(opts))
|> Js.Promise.then_((result: browserResult) => {
     Js.log(result.resultType);
     resolve();
   })
|> ignore;
```

```reason
open Js.Promise;
open ReactNativeInAppBrowser;

openAuthIos("https://example.com/auth", "myschema://auth", `IosOptions(iosOptions()))
|> Js.Promise.then_((result: authResult) => {
     switch (result.url) {
       | Some(url) => Js.log(url)
       | None => Js.log("Something went wrong")
     };
     resolve();
   })
|> ignore;
```

### Types

#### `authResult`

#### `browserResult`

#### `iosOptions`

#### `androidOptions`

### Methods

#### `ReactNativeInAppBrowser.openBrowser`

```reason
(string,  [ `AndroidOptions(androidOptions) | `IosOptions(iosOptions) ]) => Js.Promise.t(browserResult)
```

#### `ReactNativeInAppBrowser.close`

```reason
unit => unit
```

#### `ReactNativeInAppBrowser.openAuth`

```reason
(string, [ `AndroidOptions(androidOptions) | `IosOptions(iosOptions) ]) => Js.Promise.t(authResult)
```

#### `ReactNativeInAppBrowser.closeAuth`

```reason
unit => unit
```

---

## Changelog

Check the [changelog](./CHANGELOG.md) for more informations about recent
releases.

---

## Contribute

Read the
[contribution guidelines](https://github.com/reason-react-native/.github/blob/master/CONTRIBUTING.md)
before contributing.

## Code of Conduct

We want this community to be friendly and respectful to each other. Please read
[our full code of conduct](https://github.com/reason-react-native/.github/blob/master/CODE_OF_CONDUCT.md)
so that you can understand what actions will and will not be tolerated.
