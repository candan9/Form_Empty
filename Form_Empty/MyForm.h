#pragma once
#include <Windows.h>
#include <atlstr.h>
#include "imge_bmp.h"

namespace Form_Empty {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		
		LPCTSTR input, output;
		int Width, Height;
		int K1 = 0, K2 = 0;
		int* thresharray;
		long Size, new_size;
		BYTE* buffer;
		BYTE* raw_intensity;
		double* conv;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::ToolStripMenuItem^ fillChartToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::ToolStripMenuItem^ convolutionToolStripMenuItem;



	private: System::Windows::Forms::ToolStripMenuItem^ show›ntenseToolStripMenuItem;
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->show›ntenseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fillChartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->convolutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1112, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openToolStripMenuItem,
					this->show›ntenseToolStripMenuItem, this->fillChartToolStripMenuItem, this->convolutionToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// show›ntenseToolStripMenuItem
			// 
			this->show›ntenseToolStripMenuItem->Name = L"show›ntenseToolStripMenuItem";
			this->show›ntenseToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->show›ntenseToolStripMenuItem->Text = L"Show Intense";
			this->show›ntenseToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::show›ntenseToolStripMenuItem_Click);
			// 
			// fillChartToolStripMenuItem
			// 
			this->fillChartToolStripMenuItem->Name = L"fillChartToolStripMenuItem";
			this->fillChartToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->fillChartToolStripMenuItem->Text = L"Fill Chart";
			this->fillChartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::fillChartToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(331, 273);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(360, 27);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(316, 273);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// chart1
			// 
			chartArea3->AxisX->Interval = 5;
			chartArea3->AxisX2->Interval = 1;
			chartArea3->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chart1->Legends->Add(legend3);
			this->chart1->Location = System::Drawing::Point(682, 27);
			this->chart1->Name = L"chart1";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"chart";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt32;
			series3->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt32;
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(430, 413);
			this->chart1->TabIndex = 3;
			this->chart1->Text = L"chart1";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(360, 213);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(353, 244);
			this->pictureBox3->TabIndex = 4;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(0, 213);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(353, 244);
			this->pictureBox4->TabIndex = 5;
			this->pictureBox4->TabStop = false;
			// 
			// convolutionToolStripMenuItem
			// 
			this->convolutionToolStripMenuItem->Name = L"convolutionToolStripMenuItem";
			this->convolutionToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->convolutionToolStripMenuItem->Text = L"Convolution";
			this->convolutionToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::convolutionToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1112, 452);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		CString str;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			str = openFileDialog1->FileName;
			input = (LPCTSTR)str;
			//BMP image reading
			buffer = LoadBMP(Width, Height, Size, input);
			pictureBox1->Width = Width;
			pictureBox1->Height = Height;
			pictureBox1->ImageLocation = openFileDialog1->FileName;
		}
	}
	private: System::Void show›ntenseToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	    raw_intensity = ConvertBMPToIntensity(buffer, Width, Height);
		pictureBox2->Width = Width;
		pictureBox2->Height = Height;
		Bitmap^ surface = gcnew Bitmap(pictureBox2->Width, pictureBox2->Height );
		pictureBox2->Image = surface;
		Color c;
		for(int row = 0; row < Height; row++)
		{
			for (int col = 0; col < Width; col++)
			{
				c = Color::FromArgb(*(raw_intensity + row * Width+col),*(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col));
				surface->SetPixel(col, row, c);
			}
		}
		
	}
	public: void letConvolution() {
		int segmentB[9] = { 0,1,0,1,1,1,0,1,0};
		 conv = new double[(Height-4)*(Width-4)];
		double temp = 0;
		for (int i = 0; i < Height-4;i++)
		{
			for (int j = 0; j < Width - 4; j++)
			{
				temp = 0;
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l <3; l++)
					{
						temp += raw_intensity[(i + k) * Width + j + l] * segmentB[i+k+l];	
					}
				}
				conv[i * (Width - 4) + j] = 0,1*temp;
			}
		}
	}
	public: void meanAlg() {
		for (int row = 0; row < Height; row++)
		{
			for (int col = 0; col < Width; col++)
			{
				raw_intensity[(col+1) + (row +1)* Width] =(raw_intensity[(col ) + (row ) * Width]+ raw_intensity[col  + (row + 1) * Width]+ raw_intensity[(col ) + (row + 2) * Width]
					+raw_intensity[(col + 1) + (row ) * Width]+ raw_intensity[(col +1) + (row + 2) * Width]+
					raw_intensity[(col +2)+(row)*Width] + raw_intensity[(col+2) + (row + 1) * Width] + raw_intensity[(col+2)+(row + 2) * Width])/8 ;
			}
		}
	}
    public: void letKmeans() {
			   int k1 = 80, k2 = 180;
			   int cK1 = 0, cK2 = 0;
			   while (1) {
				   
				   for (int i = 0; i < 256; i++)
				   {
					   int hold = k1 - i, hold2 = k2 - i;
					   if (hold < 0)hold *= -1;
					   if (hold2 < 0)hold2 *= -1;
					   if (hold < hold2) {
						   k1 += i * thresharray[i];
						   cK1 += thresharray[i];
					   }
					   else
					   {
						   k2 += i * thresharray[i];
						   cK2 += thresharray[i];
					   }

				   }
				   k1 = k1 / cK1;
				   k2 = k2 / cK2;
				   cK1 = 0, cK2 = 0;
				   if (k1 != K1 && k2 != K2) {
					   K1 = k1;
					   K2 = k2;
					   k1 = 0, k2 = 0;
					   MessageBox::Show("K1 : "+K1+" K2 : "+K2);
				   }
				 
				   else {
					   MessageBox::Show("K1 : " + K1 + " K2 : " + K2);
					   break;
				   }
			   }
			   return;
	}
    private: System::Void fillChartToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		
		int toplam = 0;
		thresharray = new int[256];
		for (int row = 0; row <= 255; row++)
		{
			for (int col = 0; col < Width*Height; col++)
			{
				if ( raw_intensity[col] == row)
				{
					toplam++;	
					
				}
			}
			chart1->Series["chart"]->Points->AddXY(row+1, toplam);
			thresharray[row] = toplam;
			toplam = 0;
			
		}//endfor
		meanAlg();
		letKmeans();
			for (int col = 0; col < Width* Height; col++)
			{
				int hold = K1 - raw_intensity[col], hold2 = K2 - raw_intensity[col];
				if (hold < 0)hold *= -1;
				if (hold2 < 0)hold2 *= -1;
				if (hold - raw_intensity[col] < hold2 - raw_intensity[col])
				{
					raw_intensity[col] = 255;
				}
				else {
					raw_intensity[col] = 0;
				}
			}
		pictureBox3->Width = Width;
		pictureBox3->Height = Height;
		Bitmap^ surface = gcnew Bitmap(pictureBox3->Width, pictureBox3->Height);
		pictureBox3->Image = surface;
		Color c;
		
		for (int row = 0; row < Height; row++)
		{
			for (int col = 0; col < Width; col++)
			{
				c = Color::FromArgb(*(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col), *(raw_intensity + row * Width + col));
				surface->SetPixel(col, row, c);
			}
		}

    }
 private: System::Void convolutionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	// letConvolution();
	 pictureBox4->Width = Width;
	 pictureBox4->Height = Height;
	 Bitmap^ surface = gcnew Bitmap(pictureBox4->Width-4, pictureBox4->Height-4);
	 pictureBox4->Image = surface;
	 Color c;

	 for (int row = 0; row < Height-4; row++)
	 {
		 for (int col = 0; col < Width-4; col++)
		 {
			 c = Color::FromArgb(*(conv + row * Width + col), *(conv + row * Width + col), *(conv + row * Width + col));
			 surface->SetPixel(col, row, c);

		 }
	 }
	 
 }
};
}

