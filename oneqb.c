#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>

//title
int title(void){
	int in;
	int go;
	int p=1;
	int a;
	int kpass=2468;//�����[�g�E�o�g���m�F�p
	int qpass=1357;//�N�C�Y�m�F�p
	int ipass=1029;//�A�C�e���m�F�p
	do{
		go=0;
		in=0;
		while(in!=0x0d){
			if(p>3){
				p=1;
			}
			if(p<1){
				p=3;
			}
			if(p==1){
				system("cls");
				printf("��START\nDEBUG\nEXIT");
				printf("\n\n\n�������(�g���L�[:����)  a : ��  \tz : ��  \tEnter : ����\n����:a,z�ő��삷��ۂ͔��p�p���ɂ��Ă�������\n");
			}
			else if(p==2){
				system("cls");
				printf("START\n��DEBUG\nEXIT");
				printf("\n\n\n�������(�g���L�[:����)  a : ��  \tz : ��  \tEnter : ����\n����:a,z�ő��삷��ۂ͔��p�p���ɂ��Ă�������\n");
			}
			else{
				system("cls");
				printf("START\nDEBUG\n��EXIT");
				printf("\n\n\n�������(�g���L�[:����)  a : ��  \tz : ��  \tEnter : ����\n����:a,z�ő��삷��ۂ͔��p�p���ɂ��Ă�������\n");
			}
			in = getch();
			switch(in){
			case 'a' : p--;break;
			case 'z' : p++;break;
			}
		}
		if(p==2){
			printf("\n�p�X���[�h����͂��Ă�������\n");
			scanf("%d",&a);
			if(a==kpass){}
			else if(a==qpass)p=4;
			else if(a==ipass)p=5;
			else{
				go=1;
			}
		}
	}while(go!=0);
	return p;
}


//select chara
int chara(void){
	int kind;
	int kettei;
	long int c;
	long int code = 114514;
	do{
		kind=0;
		kettei=0;
		while((kettei!=0x0d) && (kettei!='U')){
			if(kind<0)kind=2;
			if(kind>2)kind=0;
			system("cls");
			if(kind==0){
				printf("�E�Ƃ�I��ł�������\n\n");
				printf("name : Attacker\nHP   : 480\nPower: 20\nGard : 10\n");
				printf("\n�K�E�Z�͏��n�̌��B\nPower+20���A���̃_���[�W��^����B\n�������AHP-20�B\n");
				printf("\n\na�L�[�܂���z�L�[�őI��\n���܂�����Enter�L�[\n");
			}
			else if(kind==1){
				printf("�E�Ƃ�I��ł�������\n\n");
				printf("name : Gard Man\nHP   : 500\nPower: 10\nGard : 10\n");
				printf("\n�K�E�Z�͎��ȕېg�B\n�G��Gard��-20���A������HP+20�B\n");
				printf("\n\n\na�L�[�܂���z�L�[�őI��\n���܂�����Enter�L�[\n");
			}
			else if(kind==2){
				printf("�E�Ƃ�I��ł�������\n\n");
				printf("name : Collector\nHP   : 510\nPower: 10\nGard : 20\n");
				printf("\n�K�E�Z�̓A�C�e�����W�B\n�A�C�e���g���󂢂Ă��鎞�A2�܂Œǉ�����B\n");
				printf("\n\n\na�L�[�܂���z�L�[�őI��\n���܂�����Enter�L�[\n");
			}
			kettei = getch();
			switch(kettei){
				case 'a':kind++;break;
				case 'z':kind--;break;
			}
		}
		if(kettei=='U'){
			system("cls");
			printf("�R�[�h����͂��Ă�������\n");
			scanf("%d",&c);
			if(code==c){
				printf("\nname : Collector EX\nHP   : 700\nPower: 50\nGard : 50\n");
				printf("\n�K�E�Z�̓A�C�e�����W�B\n�A�C�e���g���󂢂Ă��鎞�A2�܂Œǉ�����B\n");
				printf("\n���̐E�ƂŌ��肵�܂��B\n\n");
				getche();
				kind=3;
			}
			else{
				printf("�R�[�h���Ⴂ�܂�\n");
				kind=4;
				Sleep(500);
			}
		}
	}while(kind>3);
	return kind;
}


//quiz
#define  NUM	96//��萔*4
#define tool 10   //item�̐�
#define extra	12

struct eQUESTION{
	char equestion[128];
	char eword[32];
	int epoint;
	int eflag;
};
struct eQUESTION ex[extra] = {
	{"�v�l�����ɗp����ꂽ������?","���v���X�̈���",1,0},
	{"","�_�������̈���",0,0},
	{"","�V�����[�̈���",0,0},
	{"","�h���g���̈���",0,0},
	{"�h�{���U�[�N�̐V���E�Ƃ͂ǂ��̂���?","�A�����J",1,0},
	{"","�F��",0,0},
	{"","�C�M���X",0,0},
	{"","�R�����r�A",0,0},
	{"���̒��œ�����Ȃ��̂͂ǂ�?","�����Q���n���X��",1,0},
	{"","�{�j�[��",0,0},
	{"","�v���s�f���X��",0,0},
	{"","�C�{��",0,0}
	
};
struct tQUESTION{						//�N�C�Y�\����
	char question[128]; 			//��蕶
	char word[32];					//����
	int  point;						//���_
	int  flag;						//�g�p����
};
struct ITEM{							//�A�C�e��
	char name[32];					//�A�C�e����
	char outline[128];				//�T�v
};
struct ITEM item[tool+1] = {				//�A�C�e�����
	{"",""},
	{"heal","HP��40��"},
	{"doping","3�^�[���̊�,�U����+30(�s���p��)"},
	{"drain","�����̍U���͕��̃_���[�W��^��,�h���C������"},
	{"direct","�h��𖳎�����50�_���[�W�^����"},
	{"gard","�h���+10(�s���p��)"},
	{"aoidance","����+10(�s���p��)"},
	{"rebirth","�U����2�{(1�^�[���s���s��)"},
	{"gard break","�G�̖h��͂�20������"},
	{"change","�G�̍U���͂Ɩh��͂̒l�����ւ���"},
	{"knowledge","�m�͂�+20����"}
};
struct tQUESTION q[NUM] = {				//����� {"��蕶","����(�I����)",�_��(0),�t���O}
	{"1���~�ɕ`����Ă���l���̖��O��?"	,"����@�g",10,0},
	{						""				,"����p��",0,0},
	{						""				,"�Ėڟ���",0,0},
	{						""				,"�����t",0,0},
	{"���O���܂̖��O�ɂ��Ȃ��Ă���A�_�C�i�}�C�g���������l�́H"	,"�m�[�x��",10,0},
	{						""				,"�j���[�g���m",0,0},
	{						""				,"���[�c�@���g",0,0},
	{						""				,"�K�K�[����",0,0},
	{"�V�}�E�}�͉��̂��܂���?"	,"�[�Ԃ��邽��",20,0},
	{						""				,"���Ԃ����f���邽��",0,0},
	{						""				,"�������",0,0},
	{						""				,"�𖾂���Ă��Ȃ�",0,0},
	{"���̑����͖�m/s���H" ,"340",10,0},
	{						""				,"300",0,0},
	{						""				,"364",0,0},
	{						""				,"250",0,0},
	{"�z�E ���Ɠǂ�?" ,"������",20,0},
	{						""				,"������",0,0},
	{						""				,"������",0,0},
	{						""				,"������",0,0},
	{"�A�i�O�}�������Ƃ��Ď葫��Z�����ǂ��ꂽ���́H"	,"�_�b�N�X�t���g",20,0},
	{						""				,"�R�[�M�[",0,0},
	{						""				,"�|�����j�A��",0,0},
	{						""				,"�h�[�x���}��",0,0},
	{"���{�œ�[�Ɉʒu���铇�́H"	,"���m����",20,0},
	{						""				,"�쒹��",0,0},
	{						""				,"�^�ߍ���",0,0},
	{						""				,"�𑨓�",0,0},
	{"ICBM�Ƃ͉��̗��̂��H"	,"�嗤�Ԓe���e",20,0},
	{						""				,"���P�b�g",0,0},
	{						""				,"�e���e�}���~�T�C��",0,0},
	{						""				,"�j���e",0,0},
	{"�C�� ���Ɠǂ�?"	,"����",30,0},
	{						""				,"�����傤",0,0},
	{						""				,"�����傤",0,0},
	{						""				,"�������",0,0},
	{"�①�ɂ��J���������ɂ���Ƃǂ��Ȃ�?"	,"�����̉��x��������",20,0},
	{						""				,"�����̉��x��������",0,0},
	{						""				,"���x�͕ς��Ȃ�",0,0},
	{						""				,"���x�݂̂����",0,0},
	{"nnasaheatok �q���g ��{���ɂ���ʂ肠��"	,"3",20,0},
	{						""				,"��",0,0},
	{						""				,"20",0,0},
	{						""				,"7",0,0},
	{"���� ���Ɠǂ�?"	,"����",20,0},
	{						""				,"�ɂ�",0,0},
	{						""				,"����",0,0},
	{						""				,"����",0,0},
	{"40980��0���?"	,"1",20,0},
	{						""				,"40980",0,0},
	{						""				,"0",0,0},
	{						""				,"20490",0,0},
	{"�J�o�̊��͐Ԃ��B�ł́A�J���V�J�̊��́H"	,"��",30,0},
	{						""				,"���F",0,0},
	{						""				,"����",0,0},
	{						""				,"��",0,0},
	{"�� ���Ɠǂ�?"	,"�����̂�",30,0},
	{						""				,"����",0,0},
	{						""				,"����",0,0},
	{						""				,"�z�E�{�E",0,0},
	{"�ǂ�݂ӂ����炵�A����?"	,"�C�^���A��",30,0},
	{						""				,"�h�C�c��",0,0},
	{						""				,"�p��",0,0},
	{						""				,"�t�����X��",0,0},
	{"�K���X�͂ǂ�ȏ�ԁH"	,"�t��",30,0},
	{						""				,"��",0,0},
	{						""				,"�C��",0,0},
	{						""				,"��ʂ��Ȃ�",0,0},
	{"�L���������X�Ԉ���ĐH�ׂ���̂�?","��",30,0},
	{						""				,"�h���[��",0,0},
	{						""				,"�n�V�r���R�E",0,0},
	{						""				,"��",0,0},
	{"���܂�̌v�Z�̑������爫���A�ΐ��l�ƌĂ΂ꂽ�l���́H"	,"�m�C�}��",40,0},
	{						""				,"�p�X�J��",0,0},
	{						""				,"�j���[�g��",0,0},
	{						""				,"�e�C���[",0,0},
	{"1+4=2,5+3=3,8+2=?"					,"5",30,0},
	{						""				,"10",0,0},
	{						""				,"6",0,0},
	{						""				,"1",0,0},
	{"�I����1�N�̑O�́H"	,"�I���O1�N",40,0},
	{						""				,"�I���O0�N",0,0},
	{						""				,"�I������",0,0},
	{						""				,"�I����0�N",0,0},
	{"�����p�`�̓��p��?","135",30,0},
	{						""				,"45",0,0},
	{						""				,"120",0,0},
	{						""				,"160",0,0},
	{"�n�͂ǂ�����ĐQ��?","�������܂�",20,0},
	{						""				,"������",0,0},
	{						""				,"����",0,0},
	{						""				,"������",0,0},
	{"���̒��łق�Ƃɂ���J�T�S�̖��O��?","�E�b�J���J�T�S",40,0},
	{						""				,"�I�I�O�C�J�T�S",0,0},
	{						""				,"�r�b�N���J�T�S",0,0},
	{						""				,"�E�G�}�c�J�T�S",0,0},
};

struct ability{								//�\�͒l
	double hp;							//�̗�
	int power;							//�U����
	int gard;							//�h���
	int speed;							//����
	int dodge;							//���
	int itembox1;						//������1
	int itembox2;						//������2
	int itembox3;						//������3
	int itembox4;						//������4
	int itembox5;						//������5
	int exp;							//�o���l
	int turnlimit;						//�A�C�e���^�[������
	int charge;							//item7�^�[������
	int sp;								//�K�E�Q�[�W
	int turnlimit2;						//���i�R��
	int uramiti;						//�ʃG���h���[�g
	int know;							//�m��
};
struct ability p[5] = {						//�����l
	{480,20,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{500,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{510,10,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{700,50,50,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{700,30,20,30,50,0,0,0,0,0,0,0,0,0,0,0,0}
};

struct SP{									//�K�E�Z
	char gage[32];
};
struct SP s[6] = {							//�Q�[�W
	{"�@�@�@�@�@max"},
	{"���@�@�@�@max"},
	{"�����@�@�@max"},
	{"�������@�@max"},
	{"���������@max"},
	{"����������max"}
};

//true end
int end(void){
	int eron;
	int ew;
	int ea;
	int eans;
	int endp;
	do{
		do{
			eron = rand()%extra/4;
			ew = rand()%4+4*eron;
		}while((ew!=0)&&(ew%4!=0));
	}while(ex[ew].eflag!=0);
	printf("%s\n",&ex[ew].equestion[0]);
	for(int j=1;j<5;j++){
		do{
			ea = rand()%4+4*eron;
		}while(ex[ea].eflag!=0);
		ex[ea].eflag=j;
		printf("%d:%s  \t",ex[ea].eflag,&ex[ea].eword[0]);
	}
	printf("\n������I��\n");
	scanf("%d",&eans);
	if(eans==ex[ew].eflag){
		endp = ex[ew].epoint;
	}
	else {
		endp=0;
	}
	
	return endp;
}

//true flag
int reset(void){
	for(int i = 0;i<extra;i++){
		ex[i].eflag = 0;
	}
	return 0;
}

//default
void modosu(void){
	for(int i=0;i<5;i++){
		if(i<=2){
			p[i].hp=500;
			if(i==0){
				p[i].power=20;
			}
			else{
				p[i].power=10;
			}
			if(i==2){
				p[i].gard=20;
			}
			else{
				p[i].gard=10;
			}
		}
		else{
			p[i].hp=700;
			if(i==3){
				p[i].power=50;
				p[i].gard=50;
			}
			else{
				p[i].power=30;
				p[i].gard=20;
				p[i].speed=30;
				p[i].dodge=50;
			}
		}
		if(i<4){
			p[i].speed=0;
			p[i].dodge=0;
			p[i].itembox1=0;
			p[i].itembox2=0;
			p[i].itembox3=0;
			p[i].itembox4=0;
			p[i].itembox5=0;
			p[i].exp=0;
			p[i].turnlimit=0;
			p[i].charge=0;
			p[i].sp=0;
			p[i].turnlimit2=0;
			p[i].uramiti=0;
			p[i].know=0;
		}
		else{}
	}
	return;
}


int main(void){
	char buf[256];
	int itai;
	int up1;
	int up2;
	int up3;
	up1=up2=up3=0;
	int enemysel;
	int pattern=0;
	srand((unsigned)time(NULL));
	
	int handan;
	int gatya;
	//quiz
	char C[128];
	int ans;
	int i,w,j,a,ron;
	int play;
	int free;
	//item&exp
	int Item;
	int keep;
	int row;
	int select;
	int key;
	int itemhandan;
	int itemact=0;
	//battle_phisical
	int go,act,c;
	int enemy=4;
	int turn;
	int kaihi;
	double damage;
	int okiba;
	int player;
	int musi;
	int END;
	int debug;
	int ptry=0;
	
	int re=0;

	int kensa;
	
	int ok;
	int henzi;
	
	while(1){
		handan = title();					//�^�C�g�����

		if(handan==3)break;
		else{								//�{��
			c=0;
			do{
				player = chara();
				printf("\n���̐E�ƂŃQ�[�����n�߂܂�\n");
				Sleep(1000);
				system("cls");
				printf("�O�Ղ̃m�[�g\n\n\n");
				if(re==0){
					printf("�܂������L����Ă��܂���B");
				}
				else if(re==1){
					printf("���͂͐푈�B\n�m�͂�����͕��a�Ȃ�B");
				}
				else if(re==2){
					printf("knowleadge�͒m�͂����߁A\n�hP�h�͕��a�̓�����");
				}
				else{
					printf("�m�͂�����΁AP�L�|����ʃ��[�g");
				}
				Sleep(1700);
				system("cls");
				printf("||Quiz & Battle||\n10�̖��������Čo���l�𓾂悤!\n�ԈႦ��ƃ|�C���g���̃_���[�W���󂯂��\n");
				printf("�o���l���D���Ȃ悤�ɐU��A�A�C�e������g���đ����|����!!\n//*Enter�̉��������ɒ��ӂ��悤//\n");
				printf("\n\n�����L�[�������Ǝn�܂�܂�\n");
				getche();
				c=0;
				if(handan==2){
					debug=1;
					p[player].know = 20;
					p[player].exp = 200;
					printf("\n\n�f�o�b�O���[�h(type know)�K�p\n");
				}
				else if(handan==4){
					debug=2;
					printf("\n\n�f�o�b�O���[�h(type question)�K�p\n");
				}
				else if(handan==5){
					debug=3;
					printf("\n\n�f�o�b�O���[�h(type item)�K�p\n");
				}
				else{}
				printf("\n�����L�[�������ƃQ�[�����n�܂�܂�");
				c = getch();
			}while(c==0);
			c=0;
			system("cls");
//------------------------------------------------------------------------------------------------------------------------------------------------------  �N�C�Y�Ɗ���U��
			printf("4���N�C�Y\n");
			printf("�����̓����𐳂�������\n���ǂꂩ�L�[�������Ǝn�܂�܂��B\n");
			getche();
			system("cls");
			for(i=1;i<11;i++){
				if((debug==1)||(debug==3))continue;
				printf("player \nhp:%.lf,exp:%d\n",p[player].hp,p[player].exp);
				printf("�c���萔 : %d",11-i);
				getche();
				system("cls");
				do{
					do{
						ron = rand()%NUM/4;
						w = rand()%4+4*ron;
					}while((w!=0)&&(w%4!=0));
				}while(q[w].flag!=0);
				printf("%s\n",&q[w].question[0]);
				for(j=1;j<5;j++){
					do{
						a = rand()%4+4*ron;
					}while(q[a].flag!=0);
					q[a].flag=j;
					printf("%d:%s  \t",q[a].flag,&q[a].word[0]);
				}
				printf("\n������I��\n");
				do{
					gets(buf);
					for(ans=0; buf[ans]; ans++){
						if( ! isdigit(buf[ans]) )break;
					}
				}while( buf[ans] );
				sscanf(buf, "%d", &ans);
				//scanf("%d",&ans);
				if(ans==q[w].flag){
					p[player].exp+=q[w].point;
					printf("����\n�o���l%d�l��\n",q[w].point);
					printf("���ɐi�ނɂ͉����L�[�������Ă�������\n");
					getche();
					system("cls");
				}
				else {
					p[player].hp-=q[w].point;
					printf("�c�O�B�����́@%d�@�ł���\n",q[w].flag);
					printf("���Ȃ���%d�_���[�W�󂯂�\n",q[w].point);
					printf("���ɐi�ނɂ͉����L�[�������Ă�������\n");
					getche();
					system("cls");
				}
			}
			printf("player \nhp:%.lf,exp:%d\n",p[player].hp,p[player].exp);
			printf("�����L�[�������Ă�������");
			getche();
			system("cls");
			if(debug==2)continue;
			
			while(p[player].exp>0){
				select=1;
				key=0;
				while(key!=0x0d){
					if(select<1)select=4;
					if(select>4)select=1;
					if(select==1){
						system("cls");
						printf("�ǂ̃X�e�[�^�X�������܂���?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("���U���� : %d\n�h��� : %d\n���� : %d\n���� :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					else if(select==2){
						system("cls");
						printf("�ǂ̃X�e�[�^�X�������܂���?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("�U���� : %d\n���h��� : %d\n���� : %d\n���� :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					else if(select==3){
						system("cls");
						printf("�ǂ̃X�e�[�^�X�������܂���?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("�U���� : %d\n�h��� : %d\n������ : %d\n���� :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					else if(select==4){
						system("cls");
						printf("�ǂ̃X�e�[�^�X�������܂���?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("�U���� : %d\n�h��� : %d\n���� : %d\n������ :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					
					key = getch();
					switch(key){
						case 'a':select--;break;
						case 'z':select++;break;
					}
				}
				do{
					printf("�o���l���ǂꂾ������U��܂���?\n10�P�ʂœ��͂��Ă�������\n");
					printf("0������U��ƃX�e�[�^�X�I���֖߂�܂�\n");
					printf("���݂̌o���l:%d     ���o���l:",p[player].exp);
					scanf("%d",&keep);
				}while((keep%10!=0)||(keep>p[player].exp));
				p[player].exp -= keep;
				if(select==1){
					p[player].power += keep;
				}
				else if(select==2){
					p[player].gard += keep;
				}
				else if(select==3){
					p[player].speed += keep;
				}
				else if(select==4){
					p[player].dodge += keep;
				}
			}
			system("cls");
			printf("�ŏI�X�e�[�^�X\n");
			printf("HP : %.lf\n�U���� : %d\n�h��� : %d\n���� : %d\n���� :%d\n"
								,p[player].hp,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
			printf("�����L�[�������Ă�������");
			getche();
			
//--------------------------------------------------------------------------------------------------------------------------------------------------------  �A�C�e��
			
			do{
				ok=1;
				system("cls");
				printf("�A�C�e���K�`��\n");
				for(gatya=1;gatya<6;gatya++){
					do{
						kensa=0;
						Item = rand()%tool+1;
						if(re==0){
							if(Item==10)kensa=1;
							else {}
						}
					}while(kensa!=0);
					if(debug==1)Item=10;
					for(j=0;j<10;j++){
						for(i=0;i<30000000;i++){}
						printf("��");
					}
					printf("\n%s : %s\n",item[Item].name,item[Item].outline);
					if(gatya==1){
						p[player].itembox1 = Item;
					}
					else if(gatya==2){
						p[player].itembox2 = Item;
					}
					else if(gatya==3){
						p[player].itembox3 = Item;
					}
					else if(gatya==4){
						p[player].itembox4 = Item;
					}
					else{
						p[player].itembox5 = Item;
					}
				}
				if(debug==3){
					printf("\n��蒼���܂���?\n\n1.�͂��@�@�@�@2.������\n");
					scanf("%d",&henzi);
					if(henzi==1)ok=0;
					else{}
				}
			}while(ok!=1);
			printf("�����L�[�������Ă�������");
			getche();
			system("cls");
			if(debug==3)continue;
			if(p[player].speed>=p[enemy].speed){
				turn=1;
			}
			else{
				turn=0;
			}
//--------------------------------------------------------------------------------------------------------------------------------------------------------  �o�g��
			do{
				damage=0;
				kaihi = 0;
				system("cls");
				printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
				if(turn==1){
					if(p[player].turnlimit2>0){									//���i�R��̏���
						itai = rand()%20+1;
						p[player].turnlimit2 -= 1;
					}
					do{
						if(p[player].charge==2){
							system("cls");
							printf("player1�͗͂𗭂߂Ă���...\n");				//item rebirth�҂�
							getche();
							break;
						}
						act=1;
						go=0;
						c=0;
						while((c!=0x0d) && ((c!='p')||(p[player].know==0))){											//�R�}���h�I��
							if(act>4)act=1;
							if(act<1)act=4;
							if(act==1){
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player1�͂ǂ����܂���?\n");
								printf("����������\n��������\n�K�E�Z\n�X�e�[�^�X\n");
							}
							else if(act==2){
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player1�͂ǂ����܂���?\n");
								printf("��������\n����������\n�K�E�Z\n�X�e�[�^�X\n");
							}
							else if(act==3){
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player1�͂ǂ����܂���?\n");
								printf("��������\n��������\n���K�E�Z\n�X�e�[�^�X\n");
							}
							
							else{
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player%d�͂ǂ����܂���?\n",turn);
								printf("��������\n��������\n�K�E�Z\n���X�e�[�^�X\n");
							}
						//	do{
						//		if (kbhit()){c = getch();break;}
						//	}while(!kbhit());
						
							
						//	while( !kbhit() )
						//		fflush(stdin);
							c = getche();
							switch(c){
								case 'a': act--;break;
								case 'z': act++;break;
							}
						}
						
					//	fflush(stdin);
						//	scanf("%*[^\n]%*c");

						
						
						if(c=='p'){
							p[player].uramiti++;
							if(p[player].uramiti==1){
								printf("\n���Ȃ��͗͂̎g��������������\n");
							}
							else if(p[player].uramiti==2){
								printf("\n���Ȃ��͂����ނ�Ƀm�[�g�����o����\n");
							}
							else if(p[player].uramiti==3){
								printf("\n���Ȃ��͉��M����Ɏ����\n");
							}
							else if(p[player].uramiti==4){
								printf("\n���Ȃ��͕�����̂Ă�\n");
							}
							Sleep(1500);
							go=1;
						}
						else if(act==1){												//��������
							printf("�U��\n");
							kaihi = rand()%1000+1;
							for(free=0;free<3000000;free++){printf("");}
							if(kaihi<=p[enemy].dodge){
								printf("������������Ȃ�����\n");
								Sleep(500);
								go=1;
							}
							else if(itai == 4){									//���i�R��ɂ�閃�
								printf("�������A�����ɂ��ē����Ȃ�\n");
								itai=0;
								go=1;
							}
							else{
								damage=p[player].power*10/p[enemy].gard;		//�_���[�W�v�Z
								if(10>damage)damage=10;
								p[enemy].hp -= damage;
								printf("%.lf�_���[�W\n",damage);
								go=1;
							}
						}
						else if(act==2){										//��������
							c=0;
							do{													//�������̑I��
								system("cls");
								if(itemact<1)itemact=5;
								if(itemact>5)itemact=1;
								if(itemact==1){
									printf("��%s  %s\n%s  %s\n%s  %s\n%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else if(itemact==2){
									printf("%s  %s\n��%s  %s\n%s  %s\n%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else if(itemact==3){
									printf("%s  %s\n%s  %s\n��%s  %s\n%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else if(itemact==4){
									printf("%s  %s\n%s  %s\n%s  %s\n��%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else{
									printf("%s  %s\n%s  %s\n%s  %s\n%s  %s\n��%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								
								printf("�g�p���� : Enter  \t  �߂� : q");
								c = getch();
								switch(c){
									case 'a': itemact--;break;
									case 'z': itemact++;break;
								}
							}while((c!=0x0d)&&(c!='q'));
							if(c==0x0d){
								if(itemact==1){									//item�g�p����
									itemhandan=p[player].itembox1;
									p[player].itembox1=0;
								}
								else if(itemact==2){
									itemhandan=p[player].itembox2;
									p[player].itembox2=0;
								}
								else if(itemact==3){
									itemhandan=p[player].itembox3;
									p[player].itembox3=0;
								}
								else if(itemact==4){
									itemhandan=p[player].itembox4;
									p[player].itembox4=0;
								}
								else{
									itemhandan=p[player].itembox5;
									p[player].itembox5=0;
								}
								if(itemhandan==1){								//item heal
									printf("\n�A�C�e�����g����!!");
									p[player].hp += 40;
									go=1;
								}
								else if(itemhandan==2){
									printf("\n�A�C�e�����g����!!\n");			//item doping
									if(p[player].turnlimit!=0){
										printf("...���A���̃A�C�e���͏d���ł��Ȃ���\n");
										Sleep(1000);
									}
									else{
										p[player].power += 30;
										p[player].turnlimit = 3;
									}
									go=0;
								}
								else if(itemhandan==3){							//item drain
									printf("\n�A�C�e�����g����!!\n");
									damage = p[player].power *10 / p[enemy].gard;
									printf("����_���[�W%.lf\n",damage);
									p[enemy].hp-=damage;
									p[player].hp += damage;
									go=1;
								}
								else if(itemhandan==4){							//item direct
									printf("\n�A�C�e�����g����!!");
									p[enemy].hp-=50;
									go=1;
								}
								else if(itemhandan==5){							//item gard
									printf("\n�A�C�e�����g����!!");
									p[player].gard += 10;
									go=0;
								}
								else if(itemhandan==6){							//item aoidance
									printf("\n�A�C�e�����g����!!");
									p[player].dodge += 10;
									go=0;
								}
								else if(itemhandan==7){							//item rebirth
									printf("\n�A�C�e�����g����!!");
									if(p[player].charge!=0){
										printf("...������͏d���ł��Ȃ�\n");
										Sleep(500);
										go=0;
									}
									else{
										p[player].power = p[player].power * 2;
										p[player].charge = 1;
										go=1;
									}
								}
								else if(itemhandan==8){							//item gard break
									printf("\n�A�C�e�����g����!!");
									p[enemy].gard -= 20;
									if(p[enemy].gard<10)p[enemy].gard = 10;
									go=1;
								}
								else if(itemhandan==9){							//change
									printf("\n�A�C�e�����g����!!");
									okiba = p[enemy].gard;
									p[enemy].gard = p[enemy].power;
									p[enemy].power = okiba;
									go=1;
								}
								else if(itemhandan==10){
									printf("\n�A�C�e�����g����!!");
									p[player].know += 20;
									go=1;
									Sleep(300);
								}
								else{
									printf("�A�C�e���͂����Ȃ���");
									Sleep(1000);
									go=0;
								}
							}
							else{
								go=0;
							}
						}
						else if(act==3){										//�K�E�Z
							c=0;
							system("cls");
							printf("%s\n",s[p[player].sp].gage);				//�K�E�Q�[�W
							printf("�g�p���� : Enter  \t  �߂� : q");
							c = getch();
							if(c==0x0d){
								if(p[player].sp==5){
									if(player==0){								//attacker �K�E
										printf("\n�K�E����\n�h�䖳������%d�_���[�W\n",p[player].power+20);
										Sleep(100);
										printf("�U����+20\n");
										Sleep(100);
										printf("������HP -20\n");
										p[player].hp -= 20;
										if(p[player].charge!=0){
											p[player].power += 40;
										}
										else{
											p[player].power += 20;
										}
										p[enemy].hp = p[enemy].hp - p[player].power;
									}
									else if(player==1){							//gard man �K�E
										printf("\n�K�E����\n�G�̖h��͂�-20����40��\n");
										Sleep(100);
										printf("�G�̖h���-20\n");
										p[enemy].gard -= 20;
										if(p[enemy].gard < 10)p[enemy].gard = 10;
										Sleep(100);
										printf("HP +20\n");
										p[player].hp += 20;
									}
									else if(player==2){							//collector �K�E
										printf("\n�K�E����\n�󂫘g������Ƃ�2�܂ŃA�C�e���ǉ�\n");
										Sleep(200);
										for(gatya=0;gatya<2;gatya++){
											Item = rand()%tool+1;
											if(p[player].itembox1==0){
												printf("\n%s : %s\n",item[Item].name,item[Item].outline);
												p[player].itembox1=Item;
											}
											else if(p[player].itembox2==0){
												printf("\n%s : %s\n",item[Item].name,item[Item].outline);
												p[player].itembox2=Item;
											}
											else if(p[player].itembox3==0){
												printf("\n%s : %s\n",item[Item].name,item[Item].outline);
												p[player].itembox3=Item;
											}
											else if(p[player].itembox4==0){
												printf("\n%s : %s\n",item[Item].name,item[Item].outline);
												p[player].itembox4=Item;
											}
											else if(p[player].itembox5==0){
												printf("\n%s : %s\n",item[Item].name,item[Item].outline);
												p[player].itembox5=Item;
											}
											else{
												if(gatya==0){
													printf("�܂��g���ׂ��ł͂Ȃ��悤��\n");
													musi=1;
													break;
												}
											}
										}
									}
									if(musi==0){								//�K�E�g�p��
										p[player].sp=-1;
										go=1;
									}
									else{
										go=0;
										musi=0;
									}
									Sleep(1000);
								}
								else{
									printf("\n�܂��g���Ȃ���\n");
									go=0;
									Sleep(300);
								}
							}
							else if(c=='q'){
								go=0;
							}
						}
						else{													//�X�e�[�^�X
							system("cls");
							printf("�X�e�[�^�X\n");
							if(p[player].know!=0){
								printf("HP : %.lf\n�U���� : %d\n����� : %d\n�����@ : %d\n��� : %d\n�m�́@ : %d",p[player].hp,p[player].power,p[player].gard,p[player].speed,p[player].dodge,p[player].know);
							}
							else{
								printf("HP : %.lf\n�U���� : %d\n����� : %d\n�����@ : %d\n��� : %d\n",p[player].hp,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
							}
							printf("\n\nEnemy\nHP : %.lf\n�U���� : %d\n����� : %d\n�����@ : %d\n��� : %d\n",p[enemy].hp,p[enemy].power,p[enemy].gard,p[enemy].speed,p[enemy].dodge);
							getche();
						}
					}while(go!=1);
					if(p[player].sp!=5){										//�Q�[�W�㏸
						p[player].sp+=1;
					}
					if(p[player].charge!=0){									//item rebirth �^�[���o�ߏ���
						p[player].charge+=1;
						if(p[player].charge==4){
							p[player].power = p[player].power/2;
							p[player].charge=0;
						}
					}
					if(p[player].turnlimit>0){									//item doping �^�[���o�ߏ���
						p[player].turnlimit-=1;
						if(p[player].turnlimit==0){
							p[player].power -= 10;
							p[player].turnlimit=0;
						}
					}
					turn=0;
					Sleep(1000);
				}
				else{															//enemy�^�[��
					if(p[player].uramiti==3){
						if(ptry==0)printf("Enemy : ...���̂��肾�H\n");
						else if(ptry==1)printf("Enemy : ...������x���Ă�?\n");
						else printf("Enemy : ����Ȃ���\n");
						Sleep(1000);
					}
					else if(p[player].uramiti==4){
						if(ptry==0)printf("Enemy : �n�n�n�n�A�ʔ��������\n�@�@�@�@�������낤�A���O�̒m���������Ă��\n");
						else if(ptry==1)printf("Enemy : ���x�͂������肳����Ȃ�...?\n");
						else printf("Enemy : ���ƂȂ����U�����Ă�΂������̂�...\n");
						p[player].uramiti=0;
						p[player].know=0;
						Sleep(1000);
						printf("Enemy�������o���Ă���\n\n");
						END=end();
						reset();
						if(END==1){
							p[enemy].hp -= 700;
							if(ptry==0)printf("Enemy : ����...���̒m���ʂɊ�������\n�@�@�@�@���̕������A���ꂩ������i���邱�Ƃ���...\n");
							else if(ptry==1)printf("Enemy : �Ȃ񂾁A�B���Ă��̂�...\n�@�@�@�@�����܂��܂�...��..��....��.....\n");
							else printf("Enemy : ������v���C�������ʂ�?\n�@�@�@�@����Ƃ�����҂��΂炵����...\n�@�@�@�@�D�ɗ����ˁ[������͕����Ƃ��Ă��\n");
							Sleep(1000);
						}
						else {
							if(ptry==0)printf("Enemy : �Ȃ񂾁A���̒��x��...\n�@�@�@�@���q��������...!\n\n");
							else if(ptry==1)printf("Enemy : �����������͂ɐ��܂��Ă�\n");
							else printf("Enemy : ���a�͂�����߂�\n");
							printf("�G�͕K�E�Z�𔭓����悤�Ƃ��Ă���...\n");
							p[enemy].sp = 1;
							ptry++;
							Sleep(1000);
						}
					}
					else{
						printf("����̍U��\n");
						enemysel = rand()%4+1;										//�U���I��
						kaihi = rand()%1000+1;
						if(kaihi<=p[player].dodge){
							printf("���킵��\n");
						}
						else if(p[enemy].sp==1){
							printf("�׈��ȃI�[�����G�𕢂��Ă���...\n");
							p[enemy].sp = 2;
							Sleep(1000);
						}
						else if(p[enemy].sp==2){
							printf("�G�͕K�E�Z�w�B��Ƒ��x���J��o����\n");
							printf("100�_���[�W�������!!\n");
							p[player].hp -= 100;
							Sleep(100);
							printf("�S�X�e�[�^�X��-20���ꂽ!!\n");
							p[player].power -= 20;
							if(p[player].power<10)p[player].power=10;
							p[player].gard -= 20;
							if(p[player].gard<10)p[player].gard=10;
							p[player].speed -= 20;
							if(p[player].speed<0)p[player].speed=0;
							p[player].dodge -= 20;
							if(p[player].dodge<0)p[player].dodge=0;
							
							p[enemy].sp = 0;
							Sleep(1000);
						}
						
						else{
							if(100*p[enemy].hp / 700 <= 30){						//�̗�30%�ȉ�
								if(up3==0){
									printf("�Ō�̗�\n�U����+%d �~ 2\n",p[player].power);
									p[enemy].power += p[player].power * 2;
									up3=1;											//1�����
								}
								else{
									pattern=enemysel;								//�ʏ�p�^�[��
								}
							}
							else if(100*p[enemy].hp / 700 <= 40){					//�̗�40%�ȉ�
								if(up2==0){
									printf("����͓������ɂȂ���\n�U����-20   ����+20\n");
									p[enemy].power -= 20;
									p[enemy].dodge += 20;
									up2=1;
								}
								else{
									pattern=enemysel;
								}
							}
							else if(100*p[enemy].hp / 700 <= 60){					//�̗�60%�ȉ�
								if(up1==0){
									printf("����͐g�������\n�h���+30\n");
									p[enemy].gard += 30;
									up1=1;
								}
								else{
									pattern=enemysel;
								}
							}
							else{
								pattern=enemysel;
							}
							if((pattern==2)&&(p[player].turnlimit>0)){				//���i�d���h�~
								pattern=1;
							}
							if((pattern==1) || (pattern==3)){						//�����̍U��
								damage=p[enemy].power*10/p[player].gard;
								if(10>damage)damage=10;
								p[player].hp -= damage;
								printf("%.lf�_���[�W\n",damage);
							}
							else if(pattern==2){									//���i�R��
								printf("���i�R��(�ڋ�)\n���Ȃ��͑���ɂ߂�\n");
								p[player].hp -= 10;
								p[player].turnlimit2 = 3;
								printf("10�_���[�W\n");
							}
							else if(pattern==4){									//�����˂�
								printf("�����˂�\n");
								damage=p[enemy].power*2*10/p[player].gard;
								if(10>damage)damage=10;
								p[player].hp -= damage;
								printf("%.lf�_���[�W\n",damage);
							}
							else{
							}
						}
					}
					pattern = 0;
					Sleep(1000);
					turn = 1;
				}
			}while(p[player].hp>0 && p[enemy].hp>0);
			
			if(p[player].hp>0)printf("\n\nwinner\n");
			else printf("\n\ndie\n");
			getche();
		}
		for(int def=0;def<NUM;def++){											//�t���O������
			q[def].flag=0;
		}
		modosu();
		up1=up2=up3=0;
		debug = 0;
		re++;
	}
	return 0;
}

