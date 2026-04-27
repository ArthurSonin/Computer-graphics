#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project7::MyForm form; // Заміни Project7 на назву твого проєкту, якщо вона інша
    Application::Run(% form);
    return 0;
}
