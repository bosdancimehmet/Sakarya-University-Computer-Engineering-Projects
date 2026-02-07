#pragma once

#include<functional>

using namespace std;
namespace graf
{
    using RenderFunction = function<void()>;
    using KeyboardFunction= function<void(int key,int action)>;
}
