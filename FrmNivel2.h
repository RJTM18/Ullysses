#pragma once

namespace Lab2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmNivel1
	/// </summary>
	public ref class FrmNivel2 : public System::Windows::Forms::Form
	{
	public:
		FrmNivel2(void)
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
		~FrmNivel2()
		{
			if (components)
			{
				delete components;
			}
		}

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
			// FrmNivel2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(842, 564);
			this->Name = L"FrmNivel2";
			this->Text = L"FrmNivel1";
			this->Load += gcnew System::EventHandler(this, &FrmNivel2::FrmNivel1_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void FrmNivel1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
