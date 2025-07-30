## **_这是一款基于 ReactNative 发布的`Android/iOS` 新架构文档预览开源库_** [三端统一使用点击这里](https://github.com/yrjwcharm/react-native-ohos/tree/feature/rnoh/docviewer)

> ### 版本：latest

<p align="center">
  <h1 align="center"> <code>rn-newarch-doc-viewer</code> </h1>
</p>
<p align="center">
    <a href="https://github.com/wonday/react-native-pdf/blob/master/LICENSE">
        <img src="https://img.shields.io/badge/license-MIT-green.svg" alt="License" />
    </a>
</p>

> [!TIP] [Github 地址](https://github.com/yrjwcharm/rn-newarch-doc-viewer)

## 安装与使用

> [!TIP] 注意 ⚠️ 本库 android/ios 仅给予 Fabric 新架构支持，旧架构不在跟进，若需旧架构支持请移步原作者<https://github.com/philipphecht/react-native-doc-viewer>

**确保你的 Android/iOS 已经开启了新架构支持 <https://reactnative.cn/docs/0.72/the-new-architecture/use-app-template>**

#### **npm**

```bash
npm install rn-newarch-doc-viewer
```

#### **yarn**

```bash
yarn add rn-newarch-doc-viewer
```

> 若想更改库的别名 react-native-doc-viewer 来导入。你则需要把 rn-newarch-doc-viewer 库修改下，重新 yarn 执行

```diff
+  "dependencies": {
    "@react-native-oh/react-native-harmony": "0.72.48",
    "patch-package": "^8.0.0",
    "postinstall-postinstall": "^2.1.0",
    "react": "18.2.0",
    "react-native": "0.72.5",
-    "rn-newarch-doc-viewer":"^0.0.17"
+   "react-native-doc-viewer":"npm:rn-newarch-doc-viewer@0.0.17",
    "react-native-ohos-docviewer": "^0.0.3"
  },
```

ios 需要

```bash
 cd ios
 bundle install && bundle exec pod install
```

下面的代码展示了这个库的基本使用场景：

```js
import React, { useEffect } from "react";
import {
  Button,
  DeviceEventEmitter,
  SafeAreaView,
  StatusBar,
  StyleSheet,
} from "react-native";
import OpenFile from "react-native-doc-viewer";
import { getBase64ImagePath } from "./imgbase64";
const App = () => {
  useEffect(() => {
    //监听文件预览下载进度
    const subscribtion = DeviceEventEmitter.addListener("RNDownloaderProgress", (event) => {
      // 添加事件处理
      console.log("Download progress:", event.progress);
    });
    return () => {
      // 清理事件监听器
      subscribtion&& subscribtion.remove();
    };
  }, []);
  const previewImage = () => {
    OpenFile.openDoc(
      [
        {
          url: "https://i.gsxcdn.com/2015162519_i828z3ug.jpeg",
          //ios required fileName
          fileName:'sample',
          //android required cache
          cache:false
        },
      ],
      (error: any, url: string) => {
        if (error) {
        } else {
          console.log(url);
        }
      }
    );
  };
  const previewWord = () => {
    OpenFile.openDoc(
      [
        {
          url: "https://calibre-ebook.com/downloads/demos/demo.docx",
           //ios required fileName
          fileName:'demo',
          //android required cache
          cache:false
        },
      ],
      (error: any, url: string) => {
        if (error) {
        } else {
          console.log(url);
        }
      }
    );
  };
  const previewBase64 = () => {
    OpenFile.openDocb64(
      [
        {
          base64: getBase64ImagePath(),
          fileName: "example",
          fileType: "jpg",
        },
      ],
      (error: any, url: string) => {
        if (error) {
        } else {
          console.log(url);
        }
      }
    );
  };
  const previewXML = () => {
    OpenFile.openDocBinaryinUrl(
      [
        {
          url: "https://storage.googleapis.com/need-sure/example",
            //ios required fileName
          fileName:'example',
          //android required cache
          cache:false
          fileType: "xml",
        },
      ],
      (error: any, url: string) => {
        if (error) {
          console.log("Error opening XML file:", error);
        } else {
          console.log(url);
        }
      }
    );
  };
  return (
    <SafeAreaView style={styles.container}>
      <StatusBar barStyle={"dark-content"} />
      <Button onPress={previewImage} title="预览图片" />
      <Button onPress={previewWord} title="预览word文档" />
      <Button onPress={previewBase64} title="base64打开预览" />
      <Button onPress={previewXML} title="预览XML" />
    </SafeAreaView>
  );
};
export default App;
const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
});
```

更多详情用法参考 [三端统一使用点击这里](https://github.com/yrjwcharm/react-native-ohos/tree/feature/rnoh/docviewer)

#### 开源不易，希望您可以动一动小手点点小 ⭐⭐

#### 👴 希望大家如有好的需求踊跃提交,如有问题请提交 issue，空闲时间会扩充与修复优化

## 开源协议

本项目基于 [The MIT License (MIT)](https://github.com/yrjwcharm/react-native-ohos-svgaplayer/blob/master/LICENSE) ，请自由地享受和参与开源。
