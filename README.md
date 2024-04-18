Roadmap:

1. 基于 GLSL ES 1.0 CFG 对编译器前端部分进行充分的功能验证，特别是LALR Parser Generator
2. 新增 LALR1 语法冲突检测：Reduce-Reduce, Reduce-Shift
3. 开发 ShaderLab Context Free Grammar 并测试语义准确性 (函数、结构体、expression、statements 以 glsl es 3.0 语法为准)
4. 分词器、语法解析、语义分析错误抛出
5. SDT 静态语义分析
6. 开发编译器后端(生成目标代码：glsl es 1.00/3.00)，添加 300-> 100 pollyfill 转码逻辑
7. 预处理器开发
8. 代码集成进 Galacean Runtime 仓库
