#include "pch.h"
#include "FrmNivel1.h"
#include "FrmMenuInicio.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Lab2::FrmMenuInicio());
    return 0;
}

