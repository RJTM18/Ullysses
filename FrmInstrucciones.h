#pragma once

namespace Lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmInstrucciones
	/// </summary>
	public ref class FrmInstrucciones : public System::Windows::Forms::Form
	{
	public:
		FrmInstrucciones(void)
		{
			InitializeComponent();
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmInstrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(-2, -4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(790, 614);
			this->panel1->TabIndex = 0;
			// 
			// FrmInstrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(785, 611);
			this->Controls->Add(this->panel1);
			this->Name = L"FrmInstrucciones";
			this->Text = L"FrmInstrucciones";
			this->Load += gcnew System::EventHandler(this, &FrmInstrucciones::FrmInstrucciones_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmInstrucciones_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
