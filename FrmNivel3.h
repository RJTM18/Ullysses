#pragma once

namespace Ullyses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmNivel3
	/// </summary>
	public ref class FrmNivel3 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel3(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FrmNivel3()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// FrmNivel3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(914, 871);
			this->Name = L"FrmNivel3";
			this->Text = L"FrmNivel3";
			this->Load += gcnew System::EventHandler(this, &FrmNivel3::FrmNivel3_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmNivel3_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
