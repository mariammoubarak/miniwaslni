#pragma once
#include "graph.h"
#include<string>
#include <windows.h>
#include <stdlib.h>
#include <msclr\marshal_cppstd.h>
graph cities;
vector<string> nodes;
stack <string> BackTrack;
vector<vector<int>> floydMatrix;
bool DFS;

namespace miniWasalni {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Imaging;

	string ToStd(String^);
	String^ ToSystem(string);

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			timer1->Stop();
		}

	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^  txt_weight;
	protected:

	protected:
	private: System::Windows::Forms::TextBox^  txt_src;
	private: System::Windows::Forms::PictureBox^  pb_des;
	private: System::Windows::Forms::Label^  lbl_from;
	private: System::Windows::Forms::Label^  lbl_to;
	private: System::Windows::Forms::Label^  lbl_distance;
	private: System::Windows::Forms::Label^  lbl_nEdges;
	private: System::Windows::Forms::Button^  btn_nextFA;
	private: System::Windows::Forms::TextBox^  txt_des;
	private: System::Windows::Forms::Button^  btn_Finish;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  btnDisplay;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Panel^  pnlDisplay;
	private: System::Windows::Forms::Panel^  pnlShortest;
	private: System::Windows::Forms::Button^  btn_findShortest;
	private: System::Windows::Forms::TextBox^  txt_shortestDest;
	private: System::Windows::Forms::TextBox^  txt_shortestSrc;
	private: System::Windows::Forms::PictureBox^  pic_car;
	private: System::Windows::Forms::Panel^  pnlUpdate;
	private: System::Windows::Forms::Panel^  pnl_Change;
	private: System::Windows::Forms::Button^  btn_done;
	private: System::Windows::Forms::Label^  lbl_header;
	private: System::Windows::Forms::TextBox^  txt_enterCost;
	private: System::Windows::Forms::TextBox^  txt_enterDest;
	private: System::Windows::Forms::PictureBox^  picDest;
	private: System::Windows::Forms::TextBox^  txt_enterSrc;
	private: System::Windows::Forms::PictureBox^  picSrc;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  btn_AddPath;
	private: System::Windows::Forms::Button^  btn_DeletePath;
	private: System::Windows::Forms::Button^  btn_UpdatePath;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  btnBack3;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnBack2;

	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnBacktoMain;
	private: System::Windows::Forms::TreeView^  tView_Display;
	private: System::Windows::Forms::Panel^  pnlMainMenu;
private: System::Windows::Forms::PictureBox^  pic_way;
private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::TextBox^  txt_root;
	private: System::Windows::Forms::RichTextBox^  txt_DFS;
	private: System::Windows::Forms::Button^  btn_root;

	private: System::Windows::Forms::Button^  btn_BFS;

	private: System::Windows::Forms::Button^  btn_normalDisplay;

	private: System::Windows::Forms::Button^  btn_DFS;
	private: System::Windows::Forms::Label^  lbl_enterStart;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::DataGridView^  dataGrid_Path;

private: System::Windows::Forms::DataGridView^  GridView;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::Button^  btn_AddCity;
private: System::Windows::Forms::Button^  btn_DeleteCity;
private: System::Windows::Forms::ComboBox^  cbxShortestPath;
	private: System::Windows::Forms::TextBox^  txt_alone;
	private: System::Windows::Forms::PictureBox^  pic_alone;
	private: System::ComponentModel::IContainer^  components;
	private:
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			System::Windows::Forms::TreeNode^  treeNode1 = (gcnew System::Windows::Forms::TreeNode(L"To .........Distance"));
			System::Windows::Forms::TreeNode^  treeNode2 = (gcnew System::Windows::Forms::TreeNode(L"From", gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode1 }));
			this->txt_weight = (gcnew System::Windows::Forms::TextBox());
			this->txt_src = (gcnew System::Windows::Forms::TextBox());
			this->pb_des = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_from = (gcnew System::Windows::Forms::Label());
			this->lbl_to = (gcnew System::Windows::Forms::Label());
			this->lbl_distance = (gcnew System::Windows::Forms::Label());
			this->lbl_nEdges = (gcnew System::Windows::Forms::Label());
			this->btn_nextFA = (gcnew System::Windows::Forms::Button());
			this->txt_des = (gcnew System::Windows::Forms::TextBox());
			this->btn_Finish = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnDisplay = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pnlDisplay = (gcnew System::Windows::Forms::Panel());
			this->pnlShortest = (gcnew System::Windows::Forms::Panel());
			this->pnlUpdate = (gcnew System::Windows::Forms::Panel());
			this->pnl_Change = (gcnew System::Windows::Forms::Panel());
			this->txt_alone = (gcnew System::Windows::Forms::TextBox());
			this->pic_alone = (gcnew System::Windows::Forms::PictureBox());
			this->btn_done = (gcnew System::Windows::Forms::Button());
			this->lbl_header = (gcnew System::Windows::Forms::Label());
			this->txt_enterCost = (gcnew System::Windows::Forms::TextBox());
			this->txt_enterDest = (gcnew System::Windows::Forms::TextBox());
			this->picDest = (gcnew System::Windows::Forms::PictureBox());
			this->txt_enterSrc = (gcnew System::Windows::Forms::TextBox());
			this->picSrc = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btn_DeleteCity = (gcnew System::Windows::Forms::Button());
			this->btn_AddCity = (gcnew System::Windows::Forms::Button());
			this->btn_AddPath = (gcnew System::Windows::Forms::Button());
			this->btn_DeletePath = (gcnew System::Windows::Forms::Button());
			this->btn_UpdatePath = (gcnew System::Windows::Forms::Button());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnBack3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnBack2 = (gcnew System::Windows::Forms::Button());
			this->btn_findShortest = (gcnew System::Windows::Forms::Button());
			this->pic_car = (gcnew System::Windows::Forms::PictureBox());
			this->dataGrid_Path = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->GridView = (gcnew System::Windows::Forms::DataGridView());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_shortestDest = (gcnew System::Windows::Forms::TextBox());
			this->txt_shortestSrc = (gcnew System::Windows::Forms::TextBox());
			this->cbxShortestPath = (gcnew System::Windows::Forms::ComboBox());
			this->pic_way = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnBacktoMain = (gcnew System::Windows::Forms::Button());
			this->txt_DFS = (gcnew System::Windows::Forms::RichTextBox());
			this->txt_root = (gcnew System::Windows::Forms::TextBox());
			this->btn_root = (gcnew System::Windows::Forms::Button());
			this->lbl_enterStart = (gcnew System::Windows::Forms::Label());
			this->btn_normalDisplay = (gcnew System::Windows::Forms::Button());
			this->btn_BFS = (gcnew System::Windows::Forms::Button());
			this->btn_DFS = (gcnew System::Windows::Forms::Button());
			this->tView_Display = (gcnew System::Windows::Forms::TreeView());
			this->pnlMainMenu = (gcnew System::Windows::Forms::Panel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_des))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->pnlDisplay->SuspendLayout();
			this->pnlShortest->SuspendLayout();
			this->pnlUpdate->SuspendLayout();
			this->pnl_Change->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_alone))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDest))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSrc))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_car))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_Path))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_way))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->pnlMainMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// txt_weight
			// 
			this->txt_weight->BackColor = System::Drawing::SystemColors::Menu;
			this->txt_weight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_weight->Location = System::Drawing::Point(287, 295);
			this->txt_weight->Margin = System::Windows::Forms::Padding(2);
			this->txt_weight->Multiline = true;
			this->txt_weight->Name = L"txt_weight";
			this->txt_weight->Size = System::Drawing::Size(341, 45);
			this->txt_weight->TabIndex = 1;
			this->txt_weight->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txt_src
			// 
			this->txt_src->BackColor = System::Drawing::SystemColors::Menu;
			this->txt_src->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_src->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_src->Location = System::Drawing::Point(160, 295);
			this->txt_src->Margin = System::Windows::Forms::Padding(2);
			this->txt_src->Multiline = true;
			this->txt_src->Name = L"txt_src";
			this->txt_src->Size = System::Drawing::Size(113, 27);
			this->txt_src->TabIndex = 4;
			this->txt_src->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// pb_des
			// 
			this->pb_des->BackColor = System::Drawing::Color::Transparent;
			this->pb_des->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pb_des.Image")));
			this->pb_des->Location = System::Drawing::Point(632, 233);
			this->pb_des->Margin = System::Windows::Forms::Padding(2);
			this->pb_des->Name = L"pb_des";
			this->pb_des->Size = System::Drawing::Size(133, 150);
			this->pb_des->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pb_des->TabIndex = 6;
			this->pb_des->TabStop = false;
			// 
			// lbl_from
			// 
			this->lbl_from->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_from->ForeColor = System::Drawing::Color::DarkCyan;
			this->lbl_from->Location = System::Drawing::Point(175, 385);
			this->lbl_from->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_from->Name = L"lbl_from";
			this->lbl_from->Size = System::Drawing::Size(98, 32);
			this->lbl_from->TabIndex = 8;
			this->lbl_from->Text = L"From";
			// 
			// lbl_to
			// 
			this->lbl_to->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_to->ForeColor = System::Drawing::Color::DarkCyan;
			this->lbl_to->Location = System::Drawing::Point(665, 385);
			this->lbl_to->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_to->Name = L"lbl_to";
			this->lbl_to->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->lbl_to->Size = System::Drawing::Size(74, 32);
			this->lbl_to->TabIndex = 9;
			this->lbl_to->Text = L"To";
			// 
			// lbl_distance
			// 
			this->lbl_distance->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbl_distance->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_distance->ForeColor = System::Drawing::Color::DarkCyan;
			this->lbl_distance->Location = System::Drawing::Point(373, 355);
			this->lbl_distance->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_distance->Name = L"lbl_distance";
			this->lbl_distance->Padding = System::Windows::Forms::Padding(15, 0, 0, 0);
			this->lbl_distance->Size = System::Drawing::Size(170, 32);
			this->lbl_distance->TabIndex = 10;
			this->lbl_distance->Text = L"Distance";
			this->lbl_distance->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lbl_nEdges
			// 
			this->lbl_nEdges->BackColor = System::Drawing::Color::MintCream;
			this->lbl_nEdges->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_nEdges->ForeColor = System::Drawing::Color::DarkCyan;
			this->lbl_nEdges->Location = System::Drawing::Point(288, 133);
			this->lbl_nEdges->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_nEdges->Name = L"lbl_nEdges";
			this->lbl_nEdges->Size = System::Drawing::Size(410, 72);
			this->lbl_nEdges->TabIndex = 12;
			this->lbl_nEdges->Text = L"Enter your graph:";
			this->lbl_nEdges->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_nextFA
			// 
			this->btn_nextFA->BackColor = System::Drawing::SystemColors::Control;
			this->btn_nextFA->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_nextFA->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_nextFA->ForeColor = System::Drawing::Color::DarkCyan;
			this->btn_nextFA->Location = System::Drawing::Point(398, 421);
			this->btn_nextFA->Margin = System::Windows::Forms::Padding(2);
			this->btn_nextFA->Name = L"btn_nextFA";
			this->btn_nextFA->Size = System::Drawing::Size(131, 58);
			this->btn_nextFA->TabIndex = 14;
			this->btn_nextFA->Text = L"Next";
			this->btn_nextFA->UseVisualStyleBackColor = false;
			this->btn_nextFA->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// txt_des
			// 
			this->txt_des->BackColor = System::Drawing::SystemColors::Menu;
			this->txt_des->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txt_des->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_des->Location = System::Drawing::Point(641, 295);
			this->txt_des->Margin = System::Windows::Forms::Padding(2);
			this->txt_des->Multiline = true;
			this->txt_des->Name = L"txt_des";
			this->txt_des->Size = System::Drawing::Size(112, 27);
			this->txt_des->TabIndex = 15;
			this->txt_des->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_Finish
			// 
			this->btn_Finish->BackColor = System::Drawing::SystemColors::Control;
			this->btn_Finish->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Finish->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Finish->ForeColor = System::Drawing::Color::DarkCyan;
			this->btn_Finish->Location = System::Drawing::Point(767, 421);
			this->btn_Finish->Margin = System::Windows::Forms::Padding(2);
			this->btn_Finish->Name = L"btn_Finish";
			this->btn_Finish->Size = System::Drawing::Size(131, 58);
			this->btn_Finish->TabIndex = 16;
			this->btn_Finish->Text = L"Finish";
			this->btn_Finish->UseVisualStyleBackColor = false;
			this->btn_Finish->Visible = false;
			this->btn_Finish->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(150, 233);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(133, 150);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 18;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(734, -1);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(158, 154);
			this->pictureBox3->TabIndex = 19;
			this->pictureBox3->TabStop = false;
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::MediumVioletRed;
			this->label4->Location = System::Drawing::Point(302, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(307, 49);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Main Menu";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SeaShell;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::MediumVioletRed;
			this->button2->Location = System::Drawing::Point(223, 320);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(478, 47);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Find Shortest Path";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btnDisplay
			// 
			this->btnDisplay->BackColor = System::Drawing::Color::SeaShell;
			this->btnDisplay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDisplay->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDisplay->ForeColor = System::Drawing::Color::MediumVioletRed;
			this->btnDisplay->Location = System::Drawing::Point(223, 246);
			this->btnDisplay->Margin = System::Windows::Forms::Padding(2);
			this->btnDisplay->Name = L"btnDisplay";
			this->btnDisplay->Size = System::Drawing::Size(478, 49);
			this->btnDisplay->TabIndex = 16;
			this->btnDisplay->Text = L"Display Cities and Paths";
			this->btnDisplay->UseVisualStyleBackColor = false;
			this->btnDisplay->Click += gcnew System::EventHandler(this, &MyForm::btnDisplay_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::SeaShell;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::MediumVioletRed;
			this->button4->Location = System::Drawing::Point(223, 184);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(478, 46);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Update Cities and Paths";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::SeaShell;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::MediumVioletRed;
			this->button5->Location = System::Drawing::Point(223, 386);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(482, 51);
			this->button5->TabIndex = 18;
			this->button5->Text = L"Delete Graph";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(768, 2);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(124, 147);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 20;
			this->pictureBox1->TabStop = false;
			// 
			// pnlDisplay
			// 
			this->pnlDisplay->BackColor = System::Drawing::Color::LightSteelBlue;
			this->pnlDisplay->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlDisplay.BackgroundImage")));
			this->pnlDisplay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlDisplay->Controls->Add(this->pnlShortest);
			this->pnlDisplay->Controls->Add(this->pictureBox4);
			this->pnlDisplay->Controls->Add(this->label1);
			this->pnlDisplay->Controls->Add(this->btnBacktoMain);
			this->pnlDisplay->Controls->Add(this->txt_DFS);
			this->pnlDisplay->Controls->Add(this->txt_root);
			this->pnlDisplay->Controls->Add(this->btn_root);
			this->pnlDisplay->Controls->Add(this->lbl_enterStart);
			this->pnlDisplay->Controls->Add(this->btn_normalDisplay);
			this->pnlDisplay->Controls->Add(this->btn_BFS);
			this->pnlDisplay->Controls->Add(this->btn_DFS);
			this->pnlDisplay->Controls->Add(this->tView_Display);
			this->pnlDisplay->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlDisplay->Location = System::Drawing::Point(0, 0);
			this->pnlDisplay->Name = L"pnlDisplay";
			this->pnlDisplay->Size = System::Drawing::Size(888, 479);
			this->pnlDisplay->TabIndex = 21;
			this->pnlDisplay->Visible = false;
			// 
			// pnlShortest
			// 
			this->pnlShortest->BackColor = System::Drawing::Color::OldLace;
			this->pnlShortest->Controls->Add(this->pnlUpdate);
			this->pnlShortest->Controls->Add(this->pictureBox5);
			this->pnlShortest->Controls->Add(this->label2);
			this->pnlShortest->Controls->Add(this->btnBack2);
			this->pnlShortest->Controls->Add(this->btn_findShortest);
			this->pnlShortest->Controls->Add(this->pic_car);
			this->pnlShortest->Controls->Add(this->dataGrid_Path);
			this->pnlShortest->Controls->Add(this->GridView);
			this->pnlShortest->Controls->Add(this->label5);
			this->pnlShortest->Controls->Add(this->label6);
			this->pnlShortest->Controls->Add(this->txt_shortestDest);
			this->pnlShortest->Controls->Add(this->txt_shortestSrc);
			this->pnlShortest->Controls->Add(this->cbxShortestPath);
			this->pnlShortest->Controls->Add(this->pic_way);
			this->pnlShortest->Controls->Add(this->pictureBox7);
			this->pnlShortest->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlShortest->Location = System::Drawing::Point(0, 0);
			this->pnlShortest->Name = L"pnlShortest";
			this->pnlShortest->Size = System::Drawing::Size(888, 479);
			this->pnlShortest->TabIndex = 22;
			this->pnlShortest->Visible = false;
			// 
			// pnlUpdate
			// 
			this->pnlUpdate->BackColor = System::Drawing::Color::Thistle;
			this->pnlUpdate->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlUpdate->Controls->Add(this->pnl_Change);
			this->pnlUpdate->Controls->Add(this->flowLayoutPanel1);
			this->pnlUpdate->Controls->Add(this->pictureBox6);
			this->pnlUpdate->Controls->Add(this->label3);
			this->pnlUpdate->Controls->Add(this->btnBack3);
			this->pnlUpdate->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlUpdate->Location = System::Drawing::Point(0, 0);
			this->pnlUpdate->Name = L"pnlUpdate";
			this->pnlUpdate->Size = System::Drawing::Size(888, 479);
			this->pnlUpdate->TabIndex = 23;
			this->pnlUpdate->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pnlUpdate_Paint);
			// 
			// pnl_Change
			// 
			this->pnl_Change->BackColor = System::Drawing::Color::GhostWhite;
			this->pnl_Change->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_Change.BackgroundImage")));
			this->pnl_Change->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnl_Change->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pnl_Change->Controls->Add(this->txt_alone);
			this->pnl_Change->Controls->Add(this->pic_alone);
			this->pnl_Change->Controls->Add(this->btn_done);
			this->pnl_Change->Controls->Add(this->lbl_header);
			this->pnl_Change->Controls->Add(this->txt_enterCost);
			this->pnl_Change->Controls->Add(this->txt_enterDest);
			this->pnl_Change->Controls->Add(this->picDest);
			this->pnl_Change->Controls->Add(this->txt_enterSrc);
			this->pnl_Change->Controls->Add(this->picSrc);
			this->pnl_Change->Location = System::Drawing::Point(195, 81);
			this->pnl_Change->Name = L"pnl_Change";
			this->pnl_Change->Size = System::Drawing::Size(592, 335);
			this->pnl_Change->TabIndex = 27;
			this->pnl_Change->Visible = false;
			// 
			// txt_alone
			// 
			this->txt_alone->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_alone->ForeColor = System::Drawing::Color::DimGray;
			this->txt_alone->Location = System::Drawing::Point(215, 161);
			this->txt_alone->Multiline = true;
			this->txt_alone->Name = L"txt_alone";
			this->txt_alone->Size = System::Drawing::Size(101, 31);
			this->txt_alone->TabIndex = 11;
			this->txt_alone->Visible = false;
			// 
			// pic_alone
			// 
			this->pic_alone->BackColor = System::Drawing::Color::Transparent;
			this->pic_alone->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_alone.Image")));
			this->pic_alone->Location = System::Drawing::Point(203, 118);
			this->pic_alone->Name = L"pic_alone";
			this->pic_alone->Size = System::Drawing::Size(130, 127);
			this->pic_alone->TabIndex = 10;
			this->pic_alone->TabStop = false;
			this->pic_alone->Visible = false;
			// 
			// btn_done
			// 
			this->btn_done->BackColor = System::Drawing::Color::DarkMagenta;
			this->btn_done->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_done->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_done->ForeColor = System::Drawing::Color::LavenderBlush;
			this->btn_done->Location = System::Drawing::Point(202, 282);
			this->btn_done->Name = L"btn_done";
			this->btn_done->Size = System::Drawing::Size(152, 46);
			this->btn_done->TabIndex = 9;
			this->btn_done->UseVisualStyleBackColor = false;
			this->btn_done->Click += gcnew System::EventHandler(this, &MyForm::btn_done_Click);
			// 
			// lbl_header
			// 
			this->lbl_header->AutoSize = true;
			this->lbl_header->BackColor = System::Drawing::Color::Transparent;
			this->lbl_header->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_header->ForeColor = System::Drawing::Color::DarkMagenta;
			this->lbl_header->Location = System::Drawing::Point(2, 0);
			this->lbl_header->Name = L"lbl_header";
			this->lbl_header->Size = System::Drawing::Size(93, 39);
			this->lbl_header->TabIndex = 8;
			this->lbl_header->Text = L"here";
			// 
			// txt_enterCost
			// 
			this->txt_enterCost->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_enterCost->ForeColor = System::Drawing::Color::DimGray;
			this->txt_enterCost->Location = System::Drawing::Point(179, 224);
			this->txt_enterCost->Multiline = true;
			this->txt_enterCost->Name = L"txt_enterCost";
			this->txt_enterCost->Size = System::Drawing::Size(211, 31);
			this->txt_enterCost->TabIndex = 7;
			this->txt_enterCost->Visible = false;
			// 
			// txt_enterDest
			// 
			this->txt_enterDest->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_enterDest->ForeColor = System::Drawing::Color::DimGray;
			this->txt_enterDest->Location = System::Drawing::Point(446, 197);
			this->txt_enterDest->Multiline = true;
			this->txt_enterDest->Name = L"txt_enterDest";
			this->txt_enterDest->Size = System::Drawing::Size(103, 32);
			this->txt_enterDest->TabIndex = 5;
			this->txt_enterDest->Visible = false;
			// 
			// picDest
			// 
			this->picDest->BackColor = System::Drawing::Color::Transparent;
			this->picDest->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picDest.Image")));
			this->picDest->Location = System::Drawing::Point(437, 155);
			this->picDest->Name = L"picDest";
			this->picDest->Size = System::Drawing::Size(122, 119);
			this->picDest->TabIndex = 6;
			this->picDest->TabStop = false;
			this->picDest->Visible = false;
			// 
			// txt_enterSrc
			// 
			this->txt_enterSrc->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_enterSrc->ForeColor = System::Drawing::Color::DimGray;
			this->txt_enterSrc->Location = System::Drawing::Point(30, 210);
			this->txt_enterSrc->Multiline = true;
			this->txt_enterSrc->Name = L"txt_enterSrc";
			this->txt_enterSrc->Size = System::Drawing::Size(113, 28);
			this->txt_enterSrc->TabIndex = 0;
			this->txt_enterSrc->Visible = false;
			// 
			// picSrc
			// 
			this->picSrc->BackColor = System::Drawing::Color::Transparent;
			this->picSrc->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picSrc.Image")));
			this->picSrc->Location = System::Drawing::Point(30, 161);
			this->picSrc->Name = L"picSrc";
			this->picSrc->Size = System::Drawing::Size(130, 127);
			this->picSrc->TabIndex = 4;
			this->picSrc->TabStop = false;
			this->picSrc->Visible = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"flowLayoutPanel1.BackgroundImage")));
			this->flowLayoutPanel1->Controls->Add(this->btn_DeleteCity);
			this->flowLayoutPanel1->Controls->Add(this->btn_AddCity);
			this->flowLayoutPanel1->Controls->Add(this->btn_AddPath);
			this->flowLayoutPanel1->Controls->Add(this->btn_DeletePath);
			this->flowLayoutPanel1->Controls->Add(this->btn_UpdatePath);
			this->flowLayoutPanel1->Location = System::Drawing::Point(13, 94);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(176, 340);
			this->flowLayoutPanel1->TabIndex = 26;
			// 
			// btn_DeleteCity
			// 
			this->btn_DeleteCity->BackColor = System::Drawing::Color::DarkMagenta;
			this->btn_DeleteCity->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_DeleteCity->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_DeleteCity->ForeColor = System::Drawing::Color::Snow;
			this->btn_DeleteCity->Location = System::Drawing::Point(3, 3);
			this->btn_DeleteCity->Name = L"btn_DeleteCity";
			this->btn_DeleteCity->Size = System::Drawing::Size(132, 61);
			this->btn_DeleteCity->TabIndex = 26;
			this->btn_DeleteCity->Text = L"Delete City";
			this->btn_DeleteCity->UseVisualStyleBackColor = false;
			this->btn_DeleteCity->Click += gcnew System::EventHandler(this, &MyForm::btn_DeleteCity_Click);
			// 
			// btn_AddCity
			// 
			this->btn_AddCity->BackColor = System::Drawing::Color::DarkMagenta;
			this->btn_AddCity->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_AddCity->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_AddCity->ForeColor = System::Drawing::Color::Snow;
			this->btn_AddCity->Location = System::Drawing::Point(3, 70);
			this->btn_AddCity->Name = L"btn_AddCity";
			this->btn_AddCity->Size = System::Drawing::Size(132, 61);
			this->btn_AddCity->TabIndex = 25;
			this->btn_AddCity->Text = L"Add City";
			this->btn_AddCity->UseVisualStyleBackColor = false;
			this->btn_AddCity->Click += gcnew System::EventHandler(this, &MyForm::btn_AddCity_Click);
			// 
			// btn_AddPath
			// 
			this->btn_AddPath->BackColor = System::Drawing::Color::DarkMagenta;
			this->btn_AddPath->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_AddPath->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_AddPath->ForeColor = System::Drawing::Color::Snow;
			this->btn_AddPath->Location = System::Drawing::Point(3, 137);
			this->btn_AddPath->Name = L"btn_AddPath";
			this->btn_AddPath->Size = System::Drawing::Size(132, 61);
			this->btn_AddPath->TabIndex = 22;
			this->btn_AddPath->Text = L"Add Path";
			this->btn_AddPath->UseVisualStyleBackColor = false;
			this->btn_AddPath->Click += gcnew System::EventHandler(this, &MyForm::btn_AddPath_Click);
			// 
			// btn_DeletePath
			// 
			this->btn_DeletePath->BackColor = System::Drawing::Color::DarkMagenta;
			this->btn_DeletePath->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_DeletePath->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_DeletePath->ForeColor = System::Drawing::Color::Snow;
			this->btn_DeletePath->Location = System::Drawing::Point(3, 204);
			this->btn_DeletePath->Name = L"btn_DeletePath";
			this->btn_DeletePath->Size = System::Drawing::Size(163, 64);
			this->btn_DeletePath->TabIndex = 23;
			this->btn_DeletePath->Text = L"Delete Path";
			this->btn_DeletePath->UseVisualStyleBackColor = false;
			this->btn_DeletePath->Click += gcnew System::EventHandler(this, &MyForm::btn_DeletePath_Click);
			// 
			// btn_UpdatePath
			// 
			this->btn_UpdatePath->BackColor = System::Drawing::Color::DarkMagenta;
			this->btn_UpdatePath->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_UpdatePath->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_UpdatePath->ForeColor = System::Drawing::Color::Snow;
			this->btn_UpdatePath->Location = System::Drawing::Point(3, 274);
			this->btn_UpdatePath->Name = L"btn_UpdatePath";
			this->btn_UpdatePath->Size = System::Drawing::Size(163, 71);
			this->btn_UpdatePath->TabIndex = 24;
			this->btn_UpdatePath->Text = L"Update Path";
			this->btn_UpdatePath->UseVisualStyleBackColor = false;
			this->btn_UpdatePath->Click += gcnew System::EventHandler(this, &MyForm::btn_UpdatePath_Click);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(794, 0);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(100, 108);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 21;
			this->pictureBox6->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Thistle;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::DarkMagenta;
			this->label3->Location = System::Drawing::Point(10, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(433, 39);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Update Cities and Paths :";
			// 
			// btnBack3
			// 
			this->btnBack3->BackColor = System::Drawing::Color::Thistle;
			this->btnBack3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBack3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack3->ForeColor = System::Drawing::Color::DarkMagenta;
			this->btnBack3->Location = System::Drawing::Point(379, 424);
			this->btnBack3->Name = L"btnBack3";
			this->btnBack3->Size = System::Drawing::Size(208, 51);
			this->btnBack3->TabIndex = 1;
			this->btnBack3->Text = L"Back to Main Menu";
			this->btnBack3->UseVisualStyleBackColor = false;
			this->btnBack3->Click += gcnew System::EventHandler(this, &MyForm::btnBack3_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(794, 0);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 108);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 21;
			this->pictureBox5->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::LightCoral;
			this->label2->Location = System::Drawing::Point(34, 35);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(342, 46);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Display Shortest";
			// 
			// btnBack2
			// 
			this->btnBack2->BackColor = System::Drawing::Color::LightCoral;
			this->btnBack2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBack2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBack2->ForeColor = System::Drawing::Color::Snow;
			this->btnBack2->Location = System::Drawing::Point(334, 424);
			this->btnBack2->Name = L"btnBack2";
			this->btnBack2->Size = System::Drawing::Size(208, 51);
			this->btnBack2->TabIndex = 1;
			this->btnBack2->Text = L"Back to Main Menu";
			this->btnBack2->UseVisualStyleBackColor = false;
			this->btnBack2->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_2);
			// 
			// btn_findShortest
			// 
			this->btn_findShortest->BackColor = System::Drawing::Color::LightCoral;
			this->btn_findShortest->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_findShortest->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_findShortest->ForeColor = System::Drawing::Color::Snow;
			this->btn_findShortest->Location = System::Drawing::Point(313, 355);
			this->btn_findShortest->Name = L"btn_findShortest";
			this->btn_findShortest->Size = System::Drawing::Size(254, 51);
			this->btn_findShortest->TabIndex = 28;
			this->btn_findShortest->Text = L"Yalla!";
			this->btn_findShortest->UseVisualStyleBackColor = false;
			this->btn_findShortest->Visible = false;
			this->btn_findShortest->Click += gcnew System::EventHandler(this, &MyForm::btn_findShortest_Click);
			// 
			// pic_car
			// 
			this->pic_car->BackColor = System::Drawing::Color::Transparent;
			this->pic_car->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pic_car->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_car.Image")));
			this->pic_car->ImageLocation = L"";
			this->pic_car->Location = System::Drawing::Point(146, 174);
			this->pic_car->Name = L"pic_car";
			this->pic_car->Size = System::Drawing::Size(106, 101);
			this->pic_car->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pic_car->TabIndex = 24;
			this->pic_car->TabStop = false;
			this->pic_car->Visible = false;
			// 
			// dataGrid_Path
			// 
			this->dataGrid_Path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGrid_Path->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid_Path->BackgroundColor = System::Drawing::Color::Salmon;
			this->dataGrid_Path->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_Path->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGrid_Path->Location = System::Drawing::Point(136, 300);
			this->dataGrid_Path->Name = L"dataGrid_Path";
			this->dataGrid_Path->RowHeadersVisible = false;
			this->dataGrid_Path->Size = System::Drawing::Size(577, 40);
			this->dataGrid_Path->TabIndex = 28;
			this->dataGrid_Path->Visible = false;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			// 
			// GridView
			// 
			this->GridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->GridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->GridView->BackgroundColor = System::Drawing::Color::LightCoral;
			this->GridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->GridView->Location = System::Drawing::Point(231, 130);
			this->GridView->Name = L"GridView";
			this->GridView->RowHeadersVisible = false;
			this->GridView->Size = System::Drawing::Size(407, 163);
			this->GridView->TabIndex = 30;
			this->GridView->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::LightCoral;
			this->label5->Location = System::Drawing::Point(788, 122);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 39);
			this->label5->TabIndex = 31;
			this->label5->Text = L"To:";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::LightCoral;
			this->label6->Location = System::Drawing::Point(3, 119);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(115, 39);
			this->label6->TabIndex = 32;
			this->label6->Text = L"From:";
			this->label6->Visible = false;
			// 
			// txt_shortestDest
			// 
			this->txt_shortestDest->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txt_shortestDest->ForeColor = System::Drawing::Color::Salmon;
			this->txt_shortestDest->Location = System::Drawing::Point(772, 201);
			this->txt_shortestDest->Multiline = true;
			this->txt_shortestDest->Name = L"txt_shortestDest";
			this->txt_shortestDest->Size = System::Drawing::Size(90, 37);
			this->txt_shortestDest->TabIndex = 27;
			this->txt_shortestDest->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_shortestDest->Visible = false;
			// 
			// txt_shortestSrc
			// 
			this->txt_shortestSrc->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txt_shortestSrc->ForeColor = System::Drawing::Color::Salmon;
			this->txt_shortestSrc->Location = System::Drawing::Point(33, 201);
			this->txt_shortestSrc->Multiline = true;
			this->txt_shortestSrc->Name = L"txt_shortestSrc";
			this->txt_shortestSrc->Size = System::Drawing::Size(90, 37);
			this->txt_shortestSrc->TabIndex = 26;
			this->txt_shortestSrc->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_shortestSrc->Visible = false;
			// 
			// cbxShortestPath
			// 
			this->cbxShortestPath->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cbxShortestPath->FormattingEnabled = true;
			this->cbxShortestPath->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Path between two cities", L"Distance between all cities" });
			this->cbxShortestPath->Location = System::Drawing::Point(315, 41);
			this->cbxShortestPath->Name = L"cbxShortestPath";
			this->cbxShortestPath->Size = System::Drawing::Size(302, 37);
			this->cbxShortestPath->TabIndex = 33;
			this->cbxShortestPath->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::cbxShortestPath_SelectedIndexChanged);
			// 
			// pic_way
			// 
			this->pic_way->BackColor = System::Drawing::Color::Transparent;
			this->pic_way->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pic_way.BackgroundImage")));
			this->pic_way->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pic_way->Location = System::Drawing::Point(3, 157);
			this->pic_way->Name = L"pic_way";
			this->pic_way->Size = System::Drawing::Size(144, 122);
			this->pic_way->TabIndex = 25;
			this->pic_way->TabStop = false;
			this->pic_way->Visible = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox7->Location = System::Drawing::Point(745, 157);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(144, 122);
			this->pictureBox7->TabIndex = 29;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(794, 0);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 108);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 21;
			this->pictureBox4->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->Location = System::Drawing::Point(13, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(228, 39);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Your Graph :";
			// 
			// btnBacktoMain
			// 
			this->btnBacktoMain->BackColor = System::Drawing::Color::LightSteelBlue;
			this->btnBacktoMain->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBacktoMain->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBacktoMain->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnBacktoMain->Location = System::Drawing::Point(331, 427);
			this->btnBacktoMain->Name = L"btnBacktoMain";
			this->btnBacktoMain->Size = System::Drawing::Size(208, 51);
			this->btnBacktoMain->TabIndex = 1;
			this->btnBacktoMain->Text = L"Back to Main Menu";
			this->btnBacktoMain->UseVisualStyleBackColor = false;
			this->btnBacktoMain->Click += gcnew System::EventHandler(this, &MyForm::btnBacktoMain_Click);
			// 
			// txt_DFS
			// 
			this->txt_DFS->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_DFS->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->txt_DFS->Location = System::Drawing::Point(306, 177);
			this->txt_DFS->Name = L"txt_DFS";
			this->txt_DFS->Size = System::Drawing::Size(236, 223);
			this->txt_DFS->TabIndex = 26;
			this->txt_DFS->Text = L"";
			this->txt_DFS->Visible = false;
			// 
			// txt_root
			// 
			this->txt_root->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_root->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->txt_root->Location = System::Drawing::Point(288, 125);
			this->txt_root->Multiline = true;
			this->txt_root->Name = L"txt_root";
			this->txt_root->Size = System::Drawing::Size(136, 46);
			this->txt_root->TabIndex = 25;
			this->txt_root->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txt_root->Visible = false;
			// 
			// btn_root
			// 
			this->btn_root->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_root->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_root->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_root->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btn_root->Location = System::Drawing::Point(486, 125);
			this->btn_root->Name = L"btn_root";
			this->btn_root->Size = System::Drawing::Size(103, 46);
			this->btn_root->TabIndex = 27;
			this->btn_root->Text = L"Enter";
			this->btn_root->UseVisualStyleBackColor = false;
			this->btn_root->Visible = false;
			this->btn_root->Click += gcnew System::EventHandler(this, &MyForm::btn_root_Click);
			// 
			// lbl_enterStart
			// 
			this->lbl_enterStart->AutoSize = true;
			this->lbl_enterStart->BackColor = System::Drawing::Color::Transparent;
			this->lbl_enterStart->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_enterStart->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->lbl_enterStart->Location = System::Drawing::Point(214, 80);
			this->lbl_enterStart->Name = L"lbl_enterStart";
			this->lbl_enterStart->Size = System::Drawing::Size(633, 34);
			this->lbl_enterStart->TabIndex = 32;
			this->lbl_enterStart->Text = L"Enter the city you would like to start with : ";
			this->lbl_enterStart->Visible = false;
			// 
			// btn_normalDisplay
			// 
			this->btn_normalDisplay->BackColor = System::Drawing::Color::LightSteelBlue;
			this->btn_normalDisplay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_normalDisplay->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_normalDisplay->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btn_normalDisplay->Location = System::Drawing::Point(5, 120);
			this->btn_normalDisplay->Name = L"btn_normalDisplay";
			this->btn_normalDisplay->Size = System::Drawing::Size(208, 51);
			this->btn_normalDisplay->TabIndex = 29;
			this->btn_normalDisplay->Text = L"Display Paths";
			this->btn_normalDisplay->UseVisualStyleBackColor = false;
			this->btn_normalDisplay->Click += gcnew System::EventHandler(this, &MyForm::button6_Click_1);
			// 
			// btn_BFS
			// 
			this->btn_BFS->BackColor = System::Drawing::Color::LightSteelBlue;
			this->btn_BFS->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_BFS->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_BFS->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btn_BFS->Location = System::Drawing::Point(5, 181);
			this->btn_BFS->Name = L"btn_BFS";
			this->btn_BFS->Size = System::Drawing::Size(208, 51);
			this->btn_BFS->TabIndex = 30;
			this->btn_BFS->Text = L"BFS";
			this->btn_BFS->UseVisualStyleBackColor = false;
			this->btn_BFS->Click += gcnew System::EventHandler(this, &MyForm::btn_BFS_Click);
			// 
			// btn_DFS
			// 
			this->btn_DFS->BackColor = System::Drawing::Color::LightSteelBlue;
			this->btn_DFS->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_DFS->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_DFS->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btn_DFS->Location = System::Drawing::Point(5, 247);
			this->btn_DFS->Name = L"btn_DFS";
			this->btn_DFS->Size = System::Drawing::Size(208, 51);
			this->btn_DFS->TabIndex = 31;
			this->btn_DFS->Text = L"DFS";
			this->btn_DFS->UseVisualStyleBackColor = false;
			this->btn_DFS->Click += gcnew System::EventHandler(this, &MyForm::btn_DFS_Click_1);
			// 
			// tView_Display
			// 
			this->tView_Display->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->tView_Display->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tView_Display->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->tView_Display->LineColor = System::Drawing::Color::Teal;
			this->tView_Display->Location = System::Drawing::Point(219, 78);
			this->tView_Display->Name = L"tView_Display";
			treeNode1->Checked = true;
			treeNode1->Name = L"Node3";
			treeNode1->Text = L"To .........Distance";
			treeNode2->Checked = true;
			treeNode2->Name = L"Node0";
			treeNode2->Text = L"From";
			this->tView_Display->Nodes->AddRange(gcnew cli::array< System::Windows::Forms::TreeNode^  >(1) { treeNode2 });
			this->tView_Display->Size = System::Drawing::Size(470, 336);
			this->tView_Display->TabIndex = 24;
			this->tView_Display->Visible = false;
			// 
			// pnlMainMenu
			// 
			this->pnlMainMenu->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->pnlMainMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnlMainMenu.BackgroundImage")));
			this->pnlMainMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnlMainMenu->Controls->Add(this->pnlDisplay);
			this->pnlMainMenu->Controls->Add(this->pictureBox1);
			this->pnlMainMenu->Controls->Add(this->button5);
			this->pnlMainMenu->Controls->Add(this->button4);
			this->pnlMainMenu->Controls->Add(this->btnDisplay);
			this->pnlMainMenu->Controls->Add(this->button2);
			this->pnlMainMenu->Controls->Add(this->label4);
			this->pnlMainMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlMainMenu->ForeColor = System::Drawing::Color::Crimson;
			this->pnlMainMenu->Location = System::Drawing::Point(0, 0);
			this->pnlMainMenu->Margin = System::Windows::Forms::Padding(2);
			this->pnlMainMenu->Name = L"pnlMainMenu";
			this->pnlMainMenu->Size = System::Drawing::Size(888, 479);
			this->pnlMainMenu->TabIndex = 17;
			this->pnlMainMenu->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 17);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::MintCream;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(888, 479);
			this->Controls->Add(this->pnlMainMenu);
			this->Controls->Add(this->btn_Finish);
			this->Controls->Add(this->txt_des);
			this->Controls->Add(this->btn_nextFA);
			this->Controls->Add(this->lbl_nEdges);
			this->Controls->Add(this->lbl_distance);
			this->Controls->Add(this->lbl_to);
			this->Controls->Add(this->lbl_from);
			this->Controls->Add(this->pb_des);
			this->Controls->Add(this->txt_src);
			this->Controls->Add(this->txt_weight);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox3);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::Beige;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Wasalni-وصلني";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pb_des))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->pnlDisplay->ResumeLayout(false);
			this->pnlDisplay->PerformLayout();
			this->pnlShortest->ResumeLayout(false);
			this->pnlShortest->PerformLayout();
			this->pnlUpdate->ResumeLayout(false);
			this->pnlUpdate->PerformLayout();
			this->pnl_Change->ResumeLayout(false);
			this->pnl_Change->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_alone))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picDest))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSrc))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_car))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_Path))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->GridView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pic_way))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->pnlMainMenu->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {	

			 if (ToStd(txt_des->Text) == "" || ToStd(txt_src->Text) == ""|| Convert::ToInt32(txt_weight->Text) == 0)
			 {
				 MessageBox::Show("Please enter your graph.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
			 else
				 cities.addEdge(ToStd(txt_src->Text), ToStd(txt_des->Text), Convert::ToInt32(txt_weight->Text));
			 if (cities.numEdges >= 1)
			 {
				 btn_Finish->Visible = true;
			 }
			 txt_src->Clear();
			 txt_weight->Clear();
			 txt_des->Clear();
}

private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			
			   pnlMainMenu->Visible = true;
			   pnlDisplay->Visible = false;

			if (ToStd(txt_des->Text) != "\0" && ToStd(txt_src->Text) != "\0"&& Convert::ToInt32(txt_weight->Text) != 0)
				 cities.addEdge(ToStd(txt_src->Text), ToStd(txt_des->Text), Convert::ToInt32(txt_weight->Text));
			 txt_src->Clear();
			 txt_weight->Clear();
			 txt_des->Clear();
			 btn_Finish->Visible = false;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (MessageBox::Show("Are you sure you want to exit the current graph? \n That will cause deletion of the graph ", "Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			 {
				 cities.deleteGraph();
				 pnlMainMenu->Visible = false;
			 }
			 else
				 return;	 
}

private: System::Void btnDisplay_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlDisplay->Visible = true;			
}

private: System::Void btnBacktoMain_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlMainMenu->Visible = true;
			 pnlDisplay->Visible = false;
			 tView_Display->Visible = false;
			 btn_root->Visible = false;
			 txt_root->Visible = false;
			 txt_DFS->Visible = false;
}

private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) {
			 label6->Visible = false;
			 label5->Visible = false;
			 pic_way->Visible = false;
			 pictureBox7->Visible = false;
			 pic_car->Visible = false;
			 txt_shortestDest->Visible = false;
			 txt_shortestSrc->Visible = false;
			 btn_findShortest->Visible = false;
			 GridView->Visible = false;
			 dataGrid_Path->Rows->Clear();
			 dataGrid_Path->Columns->Clear();
			 dataGrid_Path->Visible = false;
			 GridView->Rows->Clear();
			 GridView->Columns->Clear();
			 pnlShortest->Visible = false;
			 pnlDisplay->Visible = false;
			 pnlMainMenu->Visible = true;
			 pic_car->Left -= 499;

			 
			 txt_shortestDest->Clear();
			 txt_shortestSrc->Clear();
}
		  
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlShortest->Visible = true;
			 pnlDisplay->Visible = true;
			 pnlMainMenu->Visible = true;
			 pnlUpdate->Visible = false;
}
private: System::Void btnBack3_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlShortest->Visible = false;
			 pnlUpdate->Visible = false;
			 pnlDisplay->Visible = false;
			 pnlMainMenu->Visible = true;
}

private: System::Void btn_AddPath_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnl_Change->Visible = true;
			 picDest->Visible = true;
			 picSrc->Visible = true;
			 txt_enterCost->Visible = true;
			 txt_enterSrc->Visible = true;
			 txt_enterDest->Visible = true;
			 txt_alone->Visible = false;
			 pic_alone->Visible = false;
			 lbl_header->Text = ToSystem("Please Enter the New Path :");
			 btn_done->Text = ToSystem("Add");
}

private: System::Void btn_DeletePath_Click(System::Object^  sender, System::EventArgs^  e)
{
			 pnl_Change->Visible = true;
			 picDest->Visible = true;
			 picSrc->Visible = true;
			 txt_enterCost->Visible = false;
			 txt_enterSrc->Visible = true;
			 txt_enterDest->Visible = true;
			 txt_alone->Visible = false;
			 pic_alone->Visible = false;
			 lbl_header->Text = ToSystem("Please enter the path you want to delete :");
			 btn_done->Text = ToSystem("Delete");
 }
private: System::Void btn_UpdatePath_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnl_Change->Visible = true;
			 picDest->Visible = true;
			 picSrc->Visible = true;
			 txt_enterCost->Visible = true;
			 txt_enterSrc->Visible = true;
			 txt_enterDest->Visible = true;
			 txt_alone->Visible = false;
			 pic_alone->Visible = false;
			 lbl_header->Text = ToSystem("Please Enter the path you want to update:");
			 btn_done->Text = ToSystem("Update");
}

private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 pnlUpdate->Visible = true;
			 pnlDisplay->Visible = true;
			 pnlShortest->Visible = true;
			 pnlMainMenu->Visible = true;
			 pnl_Change->Visible = false;
			 
}

private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 cities.deleteGraph();
			 if (MessageBox::Show("Do you want to add another a graph?", "Suggestion", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			 {
				 pnlMainMenu->Visible = false;
			 }
			 else
				 exit(1);			 
}

private: System::Void btn_done_Click(System::Object^  sender, System::EventArgs^  e) {


			 if (btn_done->Text == ToSystem("Add"))
			 {
				 if (ToStd(txt_enterSrc->Text) == "" || ToStd(txt_enterDest->Text) == "" || Convert::ToInt32(txt_enterCost->Text) == 0)
					 MessageBox::Show("Please enter the required information.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 else
					 cities.addEdge(ToStd(txt_enterSrc->Text), ToStd(txt_enterDest->Text), Convert::ToInt32(txt_enterCost->Text));
			 }
			 if (btn_done->Text == ToSystem("Update"))
			 {
				 if (ToStd(txt_enterSrc->Text) == "" || ToStd(txt_enterDest->Text) == "" || Convert::ToInt32(txt_enterCost->Text) == 0)
					 MessageBox::Show("Please enter the required information.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 else
					 cities.updateWeight(ToStd(txt_enterSrc->Text), ToStd(txt_enterDest->Text), Convert::ToInt32(txt_enterCost->Text));
			 }
			 if (btn_done->Text == ToSystem("Delete"))
			 {
				 if (ToStd(txt_enterSrc->Text) == "" || ToStd(txt_enterDest->Text) == "")
					 MessageBox::Show("Please enter the required information.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 else
					 cities.deleteEdge(ToStd(txt_enterSrc->Text), ToStd(txt_enterDest->Text));
			 }

			 if (btn_done->Text == ToSystem("Delete City"))
			 {
				 if (ToStd(txt_alone->Text) == "")
					 MessageBox::Show("Please enter the required information.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 else
					 cities.deleteVertex(ToStd(txt_alone->Text));
			 }

			 if (btn_done->Text == ToSystem("Add City"))
			 {
				 if (ToStd(txt_alone->Text) == "")
					 MessageBox::Show("Please enter the required information.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 else
					 cities.addVertex(ToStd(txt_alone->Text));
			 }

			 txt_enterCost->Clear();
			 txt_enterDest->Clear();
			 txt_enterSrc->Clear();
			 txt_alone->Clear();

			 MessageBox::Show(" Graph Updated Successfully ", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
			 pnl_Change->Visible = false;
}
private: System::Void btn_findShortest_Click(System::Object^  sender, System::EventArgs^  e) {

			 if (ToStd(txt_shortestSrc->Text) == "" || ToStd(txt_shortestDest->Text) == "")
			 {
				 MessageBox::Show("Please Enter Cities", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			 }
			 else
			 {
				 int sum;
				 //for dijkstra Algorithm :
				 //sum = cities.dijkstra(ToStd(txt_shortestSrc->Text), ToStd(txt_shortestDest->Text), BackTrack);

				 //for  BellmanFord Algorithm : uncomment the following line
				 sum = cities.BellmanFord(ToStd(txt_shortestSrc->Text), ToStd(txt_shortestDest->Text), BackTrack);

				 if (sum == INF)
				 {
					 txt_shortestDest->Clear();
					 txt_shortestSrc->Clear();
				 }
				 else
				 {
					 btn_findShortest->Visible = false;
					 pic_car->Visible = true;
					 dataGrid_Path->Visible = true;
					 timer1->Start();

					 //Clear the Data Grid View
					 dataGrid_Path->Rows->Clear();
					 dataGrid_Path->Columns->Clear();
					 int i = 0;
					 while (!BackTrack.empty())
					 {
						 if (i == 0)
						 {
							 dataGrid_Path->Columns->Add("col", "Source");
						 }
						 else if (BackTrack.size() == 1)
						 {
							 dataGrid_Path->Columns->Add("col Dest", " Destination ");
						 }
						 else
						 {
							 dataGrid_Path->Columns->Add("col" + (i + 1), "City " + i);
						 }
						 dataGrid_Path->Rows[0]->Cells[i]->Value = (ToSystem(BackTrack.top()));
						 BackTrack.pop();
						 i++;
					 }
					 dataGrid_Path->Columns->Add("Total col", "Total Distance");
					 int ind = dataGrid_Path->ColumnCount;
					 dataGrid_Path->Rows[0]->Cells[ind - 1]->Value = (sum);
				 }
			 }
}

private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
			
			 btn_root->Visible = false;
			 txt_root->Visible = false;
			 txt_DFS->Visible = false;
			 lbl_enterStart->Visible = false;
			 tView_Display->Visible = true;

			 //Normal Display
			 tView_Display->Nodes->Clear();
			 if (cities.numVertices() > 0)
			 {
				 int i = 0;
				 for (auto it = cities.adjList.begin(); it != cities.adjList.end(); ++it)
				 {
					 if (it->second.empty()) //vertex is only a destination
						 continue;
					 tView_Display->Nodes->Add(ToSystem(it->first));

					 for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2)
						 tView_Display->Nodes[i]->Nodes->Add(ToSystem(it2->first) + " ........" + it2->second);

					 ++i;
				 }
			 }
			 else return;
}

private: System::Void btn_root_Click(System::Object^  sender, System::EventArgs^  e) {
			 nodes.clear();
			 if (cities.adjList.find(ToStd(txt_root->Text))!=cities.adjList.end())
			 {
				 if (!DFS)
					 cities.BFS(ToStd(txt_root->Text), nodes);
				 else if (DFS)
					 cities.DFS(ToStd(txt_root->Text), nodes);

				 for (int i = 0; i < nodes.size(); ++i)
					 txt_DFS->Text += ToSystem(nodes[i]) + "\n";
			 }
			 else
			 {
				 MessageBox::Show("You entered a non Existing City ,please try again", "warning");
				 txt_root->Clear();
			 }
			 
}
private: System::Void btn_DFS_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 tView_Display->Visible = false;
			 txt_DFS->Visible = true;
			 txt_root->Visible = true;
			 lbl_enterStart->Visible = true;
			 btn_root->Visible = true;
			 nodes.clear();
			 txt_DFS->Clear();
			 txt_root->Clear();
			 DFS = true;
}
private: System::Void btn_BFS_Click(System::Object^  sender, System::EventArgs^  e) {

			 tView_Display->Visible = false;
			 txt_DFS->Visible = true;
			 txt_root->Visible = true;
			 btn_root->Visible = true;
			 lbl_enterStart->Visible = true;

			 nodes.clear();
			 txt_DFS->Clear();
			 txt_root->Clear();
			 DFS = false;

}

private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			 pic_car->Left += 10;

			 if (pic_car->Location.X >= 650)
			 {
				 timer1->Stop();
			 }
 }
private: System::Void cbxShortestPath_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (cbxShortestPath->Text == "Path between two cities")
			 {
				 txt_shortestDest->Clear();
				 txt_shortestSrc->Clear();
				 label6->Visible = true;
				 label5->Visible = true;
				 pic_way->Visible = true;
				 pictureBox7->Visible = true;
				 pic_car->Visible = true;
				 txt_shortestDest->Visible = true;
				 txt_shortestSrc->Visible = true;
				 btn_findShortest->Visible = true;
				 GridView->Visible = false;

			 }
			 else
			 {
				 txt_shortestDest->Clear();
				 txt_shortestSrc->Clear();
				 label6->Visible = false;
				 label5->Visible = false;
				 pic_way->Visible = false;
				 pictureBox7->Visible = false;
				 pic_car->Visible = false;
				 txt_shortestDest->Visible = false;
				 txt_shortestSrc->Visible = false;
				 btn_findShortest->Visible = false;
				 dataGrid_Path->Visible = false;
				 GridView->Visible = true;

				 GridView->Rows->Clear();
				 GridView->Columns->Clear();

				 floydMatrix.clear();
				 floydMatrix = cities.floyd();
				 GridView->Columns->Add("header", "");
				 cities.getIndex();

				 for (int i = 0; i < floydMatrix.size(); i++)
				 {
					 GridView->Columns->Add("col" + (i + 1), ToSystem(cities.v[i].cityName));
				 }

				 for (int i = 0; i < floydMatrix.size(); i++)
				 {
					 if (i < floydMatrix.size() - 1)
					 {
						 GridView->Rows->Add();
					 }
					 GridView->Rows[i]->Cells[0]->Value = ToSystem(cities.v[i].cityName);
					 for (int j = 0; j < floydMatrix.size(); j++)
					 {
						 if (floydMatrix[i][j] == INF)
						 {
							 GridView->Rows[i]->Cells[j + 1]->Value = "No Path";
							 continue;
						 }
						 GridView->Rows[i]->Cells[j + 1]->Value = floydMatrix[i][j];
					 }
				 }
			 }
}
private: System::Void btn_DeleteCity_Click(System::Object^  sender, System::EventArgs^  e) {

			 pnl_Change->Visible = true;
			 picDest->Visible = false;
			 picSrc->Visible = false;
			 txt_enterDest->Visible = false;
			 txt_enterCost->Visible = false;
			 txt_enterSrc->Visible = false;
			 txt_alone->Visible = true;
			 pic_alone->Visible = true;

			 lbl_header->Text = ToSystem("Please Enter the City you want to Delete:");
			 btn_done->Text = ToSystem("Delete City");
}
private: System::Void btn_AddCity_Click(System::Object^  sender, System::EventArgs^  e) {

			 pnl_Change->Visible = true;
			 picDest->Visible = false;
			 picSrc->Visible = false;
			 txt_enterDest->Visible = false;
			 txt_enterCost->Visible = false;
			 txt_enterSrc->Visible = false;
			 txt_alone->Visible = true;
			 pic_alone->Visible = true;

			 lbl_header->Text = ToSystem("Please Enter the City you want to Add:");
			 btn_done->Text = ToSystem("Add City");
}
private: System::Void pnlUpdate_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
//converting from std to System String
String^ ToSystem(string s)
{
	String^g = gcnew String(s.c_str());
	return g;
}

//converting from System to std string
string ToStd(String^ s)
{
	string g = msclr::interop::marshal_as<string >(s);
	return g;
}
}