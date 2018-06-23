//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.NmXhdpiPh.fmx", _PLAT_ANDROID)
#pragma resource ("*.iPhone4in.fmx", _PLAT_IOS)

TForm1 *Form1;
String data[12];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 //	String SendMessage;           //보낼 텍스트 저장 함수 지정
   //	SendMessage=Edit1->Text;  //닉네임과 함께 텍스트 전송
	if(IdTCPClient1->Connected())     //전송 가능인지 확인
	{

				IdTCPClient1->Socket->Write(Edit1->Text, IndyTextEncoding(949));
				Edit1->Text="";


	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	int bufsize;
	UnicodeString receive;
	if(IdTCPClient1->Connected())
	{
		if(!IdTCPClient1->IOHandler->InputBufferIsEmpty())   //!=다음조건이 아니다
		{
			bufsize=IdTCPClient1->IOHandler->InputBuffer->Size;      //텍스트 크기 측정
			receive=IdTCPClient1->IOHandler->ReadString(bufsize, IndyTextEncoding(949));
			//receive함수에 받은 텍스트를 bufsize 크기 만큼 저장한다.
			Memo1->Lines->Add(receive);    //recive==온 텍스트
			Memo1->GoToTextEnd();
			Memo1->Lines->Add("------------------------------------------------------------------------------------------------");
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Panel3->BringToFront();
	Panel3->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
		  TShiftState Shift)
{
	if(Key==13)
	{
		Button1Click(Action);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Panel2->BringToFront();
	Panel2->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	data[0]=Edit2->Text;
	data[1]=Edit3->Text;
	data[2]=Edit4->Text;
	data[3]=Edit5->Text;
	data[4]=Edit6->Text;
	data[5]=Edit7->Text;
	data[6]=Edit8->Text;
	data[7]=Edit9->Text;
	data[8]=Edit10->Text;
	Panel1->Visible=false;
	Panel4->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	if(!(IP->Text==""||PORT->Text==""))  //Edit2,3가 비어있지 않을 때
	{
		IdTCPClient1->Host= IP->Text;       //host(IP주소) 설정
		IdTCPClient1->Port=StrToInt(PORT->Text); //port 설정
		IdTCPClient1->Connect();    //연결 시도
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Panel2->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Panel1->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Panel3->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	data[9]=Edit11->Text;
	Panel1->Visible=true;
	Panel3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	data[11]=Edit12->Text;
	Panel4->Visible=false;
	Panel5->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
	if (ComboBox1->ItemIndex==0) {
	 data[12]=1;
	}
	else if (ComboBox1->ItemIndex==1) {
	 data[12]=2;
	}
	Panel5->Visible=false;
	Edit1->Text=data[9]+"#"+data[0]+"#"+data[1]+"#"+data[2]+"#"+data[3]+"#"+data[4]+"#"+data[5]+"#"+data[6]+"#"+data[7]+"#"+data[8]+"#"+data[11]+"#"+data[12]+"#";

		if(IdTCPClient1->Connected())     //전송 가능인지 확인
	{
		if (data[11]=="tlqkf") {
				IdTCPClient1->Socket->Write(Edit1->Text, IndyTextEncoding(949));
				Edit1->Text="";
		}
		else{
			ShowMessage("ㅈ까고있네ㅇㅇ");
			Panel4->Visible=false;
				IdTCPClient1->Socket->Write(Edit1->Text, IndyTextEncoding(949));
				Edit1->Text="";///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	}
}
//---------------------------------------------------------------------------
