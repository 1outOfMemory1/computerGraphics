## 注意 
1. 开启nvidia独显GPU需要加入 否则默认使用集成显卡
   我的cpu是i5-8400 使用uhd630 我的有一些程序是开启了独显的 我发现独显和集显相同参数的镜头移动速度不一致
   这一点需要注意一下
```c
// 英伟达独显
extern "C" __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
// amd 独显
extern "C" __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 0x00000001;
```
2. res目录下存放shader文件 
3. utilClass 存放一些公共类，比如摄像头类 加载shader的shader_m类等等
4. sixEdgeFigure使用了glew 需要将glew32.dll放到cmake-build-debug中和exe文件放在一块
或者需要将glew32.dll文件路径添加到环境变量中,其他模块也是类似 
如果出现`exit code -1073741515 (0xC0000135)` 八成是你的动态链接库没有找到

