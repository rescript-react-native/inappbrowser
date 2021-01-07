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

### Examples

```reason
open Js.Promise;

let opts = iosOptions(~preferredBarTintColor="#ff0000", ());
openBrowserIos("https://rescript-lang.org", opts)
|> Js.Promise.then_((result: browserResult) => {
     Js.log(result.resultType);
     resolve();
   })
|> ignore;
```

```reason
open Js.Promise;

openAuthIos("https://example.com/auth", "myschema://auth", iosOptions())
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

#### `ReactNativeInAppBrowser.t`

...

### Methods

#### `ReactNativeInAppBrowser.method`

...

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
