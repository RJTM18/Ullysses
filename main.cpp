#include "pch.h"
#include "FrmNivel1.h"
#include "FrmMenuInicio.h"
#include "FrmNivel2.h"
#include "FrmNivel3.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Ullyses::FrmMenuInicio());
    return 0;
}

