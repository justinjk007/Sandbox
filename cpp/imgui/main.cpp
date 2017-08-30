#include <iostream>
#include "imgui.h"
#include "imgui_internal.h"

using namespace std;
using namespace ImGui;

int main()
{
    Text("Hello, world %d", 123);

    if (Button("OK?")) {
        // do stuff
    }

    InputText("string", buf, 256);
    SliderFloat("float", &f, 0.0f, 1.0f);
    return 0;
}
