#include "pch.h"
#include "FrmNivel1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Ullyses::FrmNivel1());
    return 0;
}

