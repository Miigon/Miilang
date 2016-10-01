# Miilang
## 简介
Miilang 是一个设计于用来支持基于DirtOS的Mud游戏逻辑的类C脚本语言。  
!!!目前处于**实验阶段**，所有的实现都不一定是最终成果，且可能不会有发布版本!!!  
对于使用所造成的计算机系统损坏、文件丢失等概不负责  
## 特性

### 语言特性
Miilang 的源代码文件后缀为`.ml`  
Miilang 采用类似C++的语法，不同的是，像lpc一样，Miilang中每个文件都是一个类，而每个文件夹都是一个命名空间。  
使用`.`来访问命名空间，使用`new`来创建一个类实例，在同一个虚拟机中不同的类(文件)可以互相访问公有成员。  

#### new
如果你想要在其他类中创建一个`./game/items/weapons/melees/knife.ml`的实例，可以这么做  
```c++
game.items.weapons.melees.knife instance = new game.items.weapons.melees.knife();
```
如果创建该实例的类存在于同一个命名空间，可以在类名开头用`.`来代替相同部分的命名空间名称  
例如：  
```c++
//两个文件均存在于 `game.items.weapons.melees`
new .knife();
//两个文件均存在于 `game.items`
new .weapons.melees.knife();
```

#### using
如果创建每个类都使用像`game.items.weapons.melees.knife`这样的名字，代码会变得长，可以像c++那样使用`using`关键字来导入某个类或命名空间。  
```c++
using game.items.weapons.melees;
new melees.knife();

using game.items.weapons.melees.knife;
new knife();
```
或者导出整个命名空间  
```c++
using game.items.weapons.melees.*
new knife();
new axe();
new katana();
```

### To Be Continued...

### 虚拟机特性
Miilang 采用编译为字节码的方式解释运行，并允许在运行时重新编译特定部分，这个特性使你可以在服务器运行时向游戏添加内容或者修改游戏内容。  
