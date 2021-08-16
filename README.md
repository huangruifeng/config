# config and log
工具库
跨平台配置文件
新增日志模块，支持多线程访问。

## 依赖
- c++11
- cmake > 3.8.2
## 生成项目
使用cmake进行生成项目
```
mkdir build
cd build
cmake ..
```
支持vscode进行生成项目，不过需要安装  CMake Tools插件
## 构建项目
在build 目录下执行
```
cmake --build .
```
## 开启测试项目
在生成项目的时候增加参数 -DENABLE_TEST
```
cmake .. -DENABLE_TEST
```
