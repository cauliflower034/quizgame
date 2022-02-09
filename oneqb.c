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
	int kpass=2468;//裏ルート・バトル確認用
	int qpass=1357;//クイズ確認用
	int ipass=1029;//アイテム確認用
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
				printf("→START\nDEBUG\nEXIT");
				printf("\n\n\n操作説明(使うキー:役割)  a : ↑  \tz : ↓  \tEnter : 決定\n注意:a,zで操作する際は半角英数にしてください\n");
			}
			else if(p==2){
				system("cls");
				printf("START\n→DEBUG\nEXIT");
				printf("\n\n\n操作説明(使うキー:役割)  a : ↑  \tz : ↓  \tEnter : 決定\n注意:a,zで操作する際は半角英数にしてください\n");
			}
			else{
				system("cls");
				printf("START\nDEBUG\n→EXIT");
				printf("\n\n\n操作説明(使うキー:役割)  a : ↑  \tz : ↓  \tEnter : 決定\n注意:a,zで操作する際は半角英数にしてください\n");
			}
			in = getch();
			switch(in){
			case 'a' : p--;break;
			case 'z' : p++;break;
			}
		}
		if(p==2){
			printf("\nパスワードを入力してください\n");
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
				printf("職業を選んでください\n\n");
				printf("name : Attacker\nHP   : 480\nPower: 20\nGard : 10\n");
				printf("\n必殺技は諸刃の剣。\nPower+20し、そのダメージを与える。\nしかし、HP-20。\n");
				printf("\n\naキーまたはzキーで選ぶ\n決まったらEnterキー\n");
			}
			else if(kind==1){
				printf("職業を選んでください\n\n");
				printf("name : Gard Man\nHP   : 500\nPower: 10\nGard : 10\n");
				printf("\n必殺技は自己保身。\n敵のGardを-20し、自分のHP+20。\n");
				printf("\n\n\naキーまたはzキーで選ぶ\n決まったらEnterキー\n");
			}
			else if(kind==2){
				printf("職業を選んでください\n\n");
				printf("name : Collector\nHP   : 510\nPower: 10\nGard : 20\n");
				printf("\n必殺技はアイテム収集。\nアイテム枠が空いている時、2つまで追加する。\n");
				printf("\n\n\naキーまたはzキーで選ぶ\n決まったらEnterキー\n");
			}
			kettei = getch();
			switch(kettei){
				case 'a':kind++;break;
				case 'z':kind--;break;
			}
		}
		if(kettei=='U'){
			system("cls");
			printf("コードを入力してください\n");
			scanf("%d",&c);
			if(code==c){
				printf("\nname : Collector EX\nHP   : 700\nPower: 50\nGard : 50\n");
				printf("\n必殺技はアイテム収集。\nアイテム枠が空いている時、2つまで追加する。\n");
				printf("\nこの職業で決定します。\n\n");
				getche();
				kind=3;
			}
			else{
				printf("コードが違います\n");
				kind=4;
				Sleep(500);
			}
		}
	}while(kind>3);
	return kind;
}


//quiz
#define  NUM	96//問題数*4
#define tool 10   //itemの数
#define extra	12

struct eQUESTION{
	char equestion[128];
	char eword[32];
	int epoint;
	int eflag;
};
struct eQUESTION ex[extra] = {
	{"思考実験に用いられた悪魔は?","ラプラスの悪魔",1,0},
	{"","ダルモンの悪魔",0,0},
	{"","シュレーの悪魔",0,0},
	{"","ドルトンの悪魔",0,0},
	{"ドボルザークの新世界とはどこのこと?","アメリカ",1,0},
	{"","宇宙",0,0},
	{"","イギリス",0,0},
	{"","コロンビア",0,0},
	{"この中で島じゃないのはどれ?","ランゲルハンス島",1,0},
	{"","ボニー島",0,0},
	{"","プロピデンス島",0,0},
	{"","イボ島",0,0}
	
};
struct tQUESTION{						//クイズ構造体
	char question[128]; 			//問題文
	char word[32];					//答え
	int  point;						//得点
	int  flag;						//使用判定
};
struct ITEM{							//アイテム
	char name[32];					//アイテム名
	char outline[128];				//概要
};
struct ITEM item[tool+1] = {				//アイテム種類
	{"",""},
	{"heal","HPを40回復"},
	{"doping","3ターンの間,攻撃力+30(行動継続)"},
	{"drain","自分の攻撃力分のダメージを与え,ドレインする"},
	{"direct","防御を無視して50ダメージ与える"},
	{"gard","防御力+10(行動継続)"},
	{"aoidance","回避力+10(行動継続)"},
	{"rebirth","攻撃力2倍(1ターン行動不可)"},
	{"gard break","敵の防御力を20下げる"},
	{"change","敵の攻撃力と防御力の値を入れ替える"},
	{"knowledge","知力を+20する"}
};
struct tQUESTION q[NUM] = {				//問題種類 {"問題文","答え(選択肢)",点数(0),フラグ}
	{"1万円に描かれている人物の名前は?"	,"福沢諭吉",10,0},
	{						""				,"野口英世",0,0},
	{						""				,"夏目漱石",0,0},
	{						""				,"樋口一葉",0,0},
	{"名前が賞の名前にもなっている、ダイナマイトをつくった人は？"	,"ノーベル",10,0},
	{						""				,"ニュートリノ",0,0},
	{						""				,"モーツァルト",0,0},
	{						""				,"ガガーリン",0,0},
	{"シマウマは何故しましま?"	,"擬態するため",20,0},
	{						""				,"仲間か判断するため",0,0},
	{						""				,"おしゃれ",0,0},
	{						""				,"解明されていない",0,0},
	{"音の速さは約何m/sか？" ,"340",10,0},
	{						""				,"300",0,0},
	{						""				,"364",0,0},
	{						""				,"250",0,0},
	{"斯界 何と読む?" ,"しかい",20,0},
	{						""				,"せかい",0,0},
	{						""				,"きかい",0,0},
	{						""				,"さかい",0,0},
	{"アナグマを狩る猟犬として手足を短く改良された犬は？"	,"ダックスフント",20,0},
	{						""				,"コーギー",0,0},
	{						""				,"ポメラニアン",0,0},
	{						""				,"ドーベルマン",0,0},
	{"日本最南端に位置する島は？"	,"沖ノ鳥島",20,0},
	{						""				,"南鳥島",0,0},
	{						""				,"与那国島",0,0},
	{						""				,"択捉島",0,0},
	{"ICBMとは何の略称か？"	,"大陸間弾道弾",20,0},
	{						""				,"ロケット",0,0},
	{						""				,"弾道弾迎撃ミサイル",0,0},
	{						""				,"核爆弾",0,0},
	{"気障 何と読む?"	,"きざ",30,0},
	{						""				,"きしょう",0,0},
	{						""				,"けしょう",0,0},
	{						""				,"きざわり",0,0},
	{"冷蔵庫を開けっ放しにするとどうなる?"	,"部屋の温度があがる",20,0},
	{						""				,"部屋の温度がさがる",0,0},
	{						""				,"温度は変わらない",0,0},
	{						""				,"湿度のみかわる",0,0},
	{"nnasaheatok ヒント 一本道にも二通りある"	,"3",20,0},
	{						""				,"里",0,0},
	{						""				,"20",0,0},
	{						""				,"7",0,0},
	{"似非 何と読む?"	,"えせ",20,0},
	{						""				,"にせ",0,0},
	{						""				,"じせ",0,0},
	{						""				,"じひ",0,0},
	{"40980の0乗は?"	,"1",20,0},
	{						""				,"40980",0,0},
	{						""				,"0",0,0},
	{						""				,"20490",0,0},
	{"カバの汗は赤い。では、カモシカの汗は？"	,"青",30,0},
	{						""				,"黄色",0,0},
	{						""				,"透明",0,0},
	{						""				,"赤",0,0},
	{"鯑 何と読む?"	,"かずのこ",30,0},
	{						""				,"きす",0,0},
	{						""				,"さば",0,0},
	{						""				,"ホウボウ",0,0},
	{"どれみふぁそらし、何語?"	,"イタリア語",30,0},
	{						""				,"ドイツ語",0,0},
	{						""				,"英語",0,0},
	{						""				,"フランス語",0,0},
	{"ガラスはどんな状態？"	,"液体",30,0},
	{						""				,"個体",0,0},
	{						""				,"気体",0,0},
	{						""				,"区別がない",0,0},
	{"キリンが時々間違って食べるものは?","鳥",30,0},
	{						""				,"ドローン",0,0},
	{						""				,"ハシビロコウ",0,0},
	{						""				,"魚",0,0},
	{"あまりの計算の速さから悪魔、火星人と呼ばれた人物は？"	,"ノイマン",40,0},
	{						""				,"パスカル",0,0},
	{						""				,"ニュートン",0,0},
	{						""				,"テイラー",0,0},
	{"1+4=2,5+3=3,8+2=?"					,"5",30,0},
	{						""				,"10",0,0},
	{						""				,"6",0,0},
	{						""				,"1",0,0},
	{"紀元後1年の前は？"	,"紀元前1年",40,0},
	{						""				,"紀元前0年",0,0},
	{						""				,"紀元初期",0,0},
	{						""				,"紀元後0年",0,0},
	{"正八角形の内角は?","135",30,0},
	{						""				,"45",0,0},
	{						""				,"120",0,0},
	{						""				,"160",0,0},
	{"馬はどうやって寝る?","立ったまま",20,0},
	{						""				,"うつ伏せ",0,0},
	{						""				,"仰向け",0,0},
	{						""				,"横向き",0,0},
	{"この中でほんとにいるカサゴの名前は?","ウッカリカサゴ",40,0},
	{						""				,"オオグイカサゴ",0,0},
	{						""				,"ビックリカサゴ",0,0},
	{						""				,"ウエマツカサゴ",0,0},
};

struct ability{								//能力値
	double hp;							//体力
	int power;							//攻撃力
	int gard;							//防御力
	int speed;							//速さ
	int dodge;							//回避率
	int itembox1;						//持ち物1
	int itembox2;						//持ち物2
	int itembox3;						//持ち物3
	int itembox4;						//持ち物4
	int itembox5;						//持ち物5
	int exp;							//経験値
	int turnlimit;						//アイテムターン効果
	int charge;							//item7ターン調整
	int sp;								//必殺ゲージ
	int turnlimit2;						//下段蹴り
	int uramiti;						//別エンドルート
	int know;							//知力
};
struct ability p[5] = {						//初期値
	{480,20,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{500,10,10,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{510,10,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{700,50,50,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{700,30,20,30,50,0,0,0,0,0,0,0,0,0,0,0,0}
};

struct SP{									//必殺技
	char gage[32];
};
struct SP s[6] = {							//ゲージ
	{"　　　　　max"},
	{"■　　　　max"},
	{"■■　　　max"},
	{"■■■　　max"},
	{"■■■■　max"},
	{"■■■■■max"}
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
	printf("\n答えを選べ\n");
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
		handan = title();					//タイトル画面

		if(handan==3)break;
		else{								//本編
			c=0;
			do{
				player = chara();
				printf("\nこの職業でゲームを始めます\n");
				Sleep(1000);
				system("cls");
				printf("軌跡のノート\n\n\n");
				if(re==0){
					printf("まだ何も記されていません。");
				}
				else if(re==1){
					printf("武力は戦争。\n知力がつくるは平和なり。");
				}
				else if(re==2){
					printf("knowleadgeは知力を高め、\n”P”は平和の頭文字");
				}
				else{
					printf("知力があれば、Pキ－から別ルート");
				}
				Sleep(1700);
				system("cls");
				printf("||Quiz & Battle||\n10個の問題を解いて経験値を得よう!\n間違えるとポイント分のダメージを受けるよ\n");
				printf("経験値を好きなように振り、アイテムを駆使して相手を倒そう!!\n//*Enterの押しすぎに注意しよう//\n");
				printf("\n\n何かキーを押すと始まります\n");
				getche();
				c=0;
				if(handan==2){
					debug=1;
					p[player].know = 20;
					p[player].exp = 200;
					printf("\n\nデバッグモード(type know)適用\n");
				}
				else if(handan==4){
					debug=2;
					printf("\n\nデバッグモード(type question)適用\n");
				}
				else if(handan==5){
					debug=3;
					printf("\n\nデバッグモード(type item)適用\n");
				}
				else{}
				printf("\n何かキーを押すとゲームが始まります");
				c = getch();
			}while(c==0);
			c=0;
			system("cls");
//------------------------------------------------------------------------------------------------------------------------------------------------------  クイズと割り振り
			printf("4択クイズ\n");
			printf("※問題の答えを正しく入力\n※どれかキーを押すと始まります。\n");
			getche();
			system("cls");
			for(i=1;i<11;i++){
				if((debug==1)||(debug==3))continue;
				printf("player \nhp:%.lf,exp:%d\n",p[player].hp,p[player].exp);
				printf("残り問題数 : %d",11-i);
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
				printf("\n答えを選べ\n");
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
					printf("正解\n経験値%d獲得\n",q[w].point);
					printf("次に進むには何かキーを押してください\n");
					getche();
					system("cls");
				}
				else {
					p[player].hp-=q[w].point;
					printf("残念。正解は　%d　でした\n",q[w].flag);
					printf("あなたは%dダメージ受けた\n",q[w].point);
					printf("次に進むには何かキーを押してください\n");
					getche();
					system("cls");
				}
			}
			printf("player \nhp:%.lf,exp:%d\n",p[player].hp,p[player].exp);
			printf("何かキーを押してください");
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
						printf("どのステータスをあげますか?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("→攻撃力 : %d\n防御力 : %d\n速さ : %d\n回避力 :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					else if(select==2){
						system("cls");
						printf("どのステータスをあげますか?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("攻撃力 : %d\n→防御力 : %d\n速さ : %d\n回避力 :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					else if(select==3){
						system("cls");
						printf("どのステータスをあげますか?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("攻撃力 : %d\n防御力 : %d\n→速さ : %d\n回避力 :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					else if(select==4){
						system("cls");
						printf("どのステータスをあげますか?\n");
						printf("player 1  exp:%d\n",p[player].exp);
						printf("攻撃力 : %d\n防御力 : %d\n速さ : %d\n→回避力 :%d\n"
								,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
					}
					
					key = getch();
					switch(key){
						case 'a':select--;break;
						case 'z':select++;break;
					}
				}
				do{
					printf("経験値をどれだけ割り振りますか?\n10単位で入力してください\n");
					printf("0を割り振るとステータス選択へ戻ります\n");
					printf("現在の経験値:%d     取り出す値:",p[player].exp);
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
			printf("最終ステータス\n");
			printf("HP : %.lf\n攻撃力 : %d\n防御力 : %d\n速さ : %d\n回避力 :%d\n"
								,p[player].hp,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
			printf("何かキーを押してください");
			getche();
			
//--------------------------------------------------------------------------------------------------------------------------------------------------------  アイテム
			
			do{
				ok=1;
				system("cls");
				printf("アイテムガチャ\n");
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
						printf("□");
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
					printf("\nやり直しますか?\n\n1.はい　　　　2.いいえ\n");
					scanf("%d",&henzi);
					if(henzi==1)ok=0;
					else{}
				}
			}while(ok!=1);
			printf("何かキーを押してください");
			getche();
			system("cls");
			if(debug==3)continue;
			if(p[player].speed>=p[enemy].speed){
				turn=1;
			}
			else{
				turn=0;
			}
//--------------------------------------------------------------------------------------------------------------------------------------------------------  バトル
			do{
				damage=0;
				kaihi = 0;
				system("cls");
				printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
				if(turn==1){
					if(p[player].turnlimit2>0){									//下段蹴りの処理
						itai = rand()%20+1;
						p[player].turnlimit2 -= 1;
					}
					do{
						if(p[player].charge==2){
							system("cls");
							printf("player1は力を溜めている...\n");				//item rebirth待ち
							getche();
							break;
						}
						act=1;
						go=0;
						c=0;
						while((c!=0x0d) && ((c!='p')||(p[player].know==0))){											//コマンド選択
							if(act>4)act=1;
							if(act<1)act=4;
							if(act==1){
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player1はどうしますか?\n");
								printf("→たたかう\nもちもの\n必殺技\nステータス\n");
							}
							else if(act==2){
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player1はどうしますか?\n");
								printf("たたかう\n→もちもの\n必殺技\nステータス\n");
							}
							else if(act==3){
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player1はどうしますか?\n");
								printf("たたかう\nもちもの\n→必殺技\nステータス\n");
							}
							
							else{
								system("cls");
								printf("player1 %.lf / 500  \tplayer2 %.lf / 700\n",p[player].hp,p[enemy].hp);
								printf("player%dはどうしますか?\n",turn);
								printf("たたかう\nもちもの\n必殺技\n→ステータス\n");
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
								printf("\nあなたは力の使い方を見直した\n");
							}
							else if(p[player].uramiti==2){
								printf("\nあなたはおもむろにノートを取り出した\n");
							}
							else if(p[player].uramiti==3){
								printf("\nあなたは鉛筆を手に取った\n");
							}
							else if(p[player].uramiti==4){
								printf("\nあなたは武器を捨てた\n");
							}
							Sleep(1500);
							go=1;
						}
						else if(act==1){												//たたかう
							printf("攻撃\n");
							kaihi = rand()%1000+1;
							for(free=0;free<3000000;free++){printf("");}
							if(kaihi<=p[enemy].dodge){
								printf("しかし当たらなかった\n");
								Sleep(500);
								go=1;
							}
							else if(itai == 4){									//下段蹴りによる麻痺
								printf("しかし、足が痛くて動けない\n");
								itai=0;
								go=1;
							}
							else{
								damage=p[player].power*10/p[enemy].gard;		//ダメージ計算
								if(10>damage)damage=10;
								p[enemy].hp -= damage;
								printf("%.lfダメージ\n",damage);
								go=1;
							}
						}
						else if(act==2){										//もちもの
							c=0;
							do{													//もちもの選択
								system("cls");
								if(itemact<1)itemact=5;
								if(itemact>5)itemact=1;
								if(itemact==1){
									printf("→%s  %s\n%s  %s\n%s  %s\n%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else if(itemact==2){
									printf("%s  %s\n→%s  %s\n%s  %s\n%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else if(itemact==3){
									printf("%s  %s\n%s  %s\n→%s  %s\n%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else if(itemact==4){
									printf("%s  %s\n%s  %s\n%s  %s\n→%s  %s\n%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								else{
									printf("%s  %s\n%s  %s\n%s  %s\n%s  %s\n→%s  %s\n"
										,item[p[player].itembox1].name,item[p[player].itembox1].outline,item[p[player].itembox2].name
										,item[p[player].itembox2].outline,item[p[player].itembox3].name,item[p[player].itembox3].outline
										,item[p[player].itembox4].name,item[p[player].itembox4].outline,item[p[player].itembox5].name,item[p[player].itembox5].outline);
								}
								
								printf("使用する : Enter  \t  戻る : q");
								c = getch();
								switch(c){
									case 'a': itemact--;break;
									case 'z': itemact++;break;
								}
							}while((c!=0x0d)&&(c!='q'));
							if(c==0x0d){
								if(itemact==1){									//item使用処理
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
									printf("\nアイテムを使った!!");
									p[player].hp += 40;
									go=1;
								}
								else if(itemhandan==2){
									printf("\nアイテムを使った!!\n");			//item doping
									if(p[player].turnlimit!=0){
										printf("...が、このアイテムは重複できないよ\n");
										Sleep(1000);
									}
									else{
										p[player].power += 30;
										p[player].turnlimit = 3;
									}
									go=0;
								}
								else if(itemhandan==3){							//item drain
									printf("\nアイテムを使った!!\n");
									damage = p[player].power *10 / p[enemy].gard;
									printf("取引ダメージ%.lf\n",damage);
									p[enemy].hp-=damage;
									p[player].hp += damage;
									go=1;
								}
								else if(itemhandan==4){							//item direct
									printf("\nアイテムを使った!!");
									p[enemy].hp-=50;
									go=1;
								}
								else if(itemhandan==5){							//item gard
									printf("\nアイテムを使った!!");
									p[player].gard += 10;
									go=0;
								}
								else if(itemhandan==6){							//item aoidance
									printf("\nアイテムを使った!!");
									p[player].dodge += 10;
									go=0;
								}
								else if(itemhandan==7){							//item rebirth
									printf("\nアイテムを使った!!");
									if(p[player].charge!=0){
										printf("...がこれは重複できない\n");
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
									printf("\nアイテムを使った!!");
									p[enemy].gard -= 20;
									if(p[enemy].gard<10)p[enemy].gard = 10;
									go=1;
								}
								else if(itemhandan==9){							//change
									printf("\nアイテムを使った!!");
									okiba = p[enemy].gard;
									p[enemy].gard = p[enemy].power;
									p[enemy].power = okiba;
									go=1;
								}
								else if(itemhandan==10){
									printf("\nアイテムを使った!!");
									p[player].know += 20;
									go=1;
									Sleep(300);
								}
								else{
									printf("アイテムはもうないよ");
									Sleep(1000);
									go=0;
								}
							}
							else{
								go=0;
							}
						}
						else if(act==3){										//必殺技
							c=0;
							system("cls");
							printf("%s\n",s[p[player].sp].gage);				//必殺ゲージ
							printf("使用する : Enter  \t  戻る : q");
							c = getch();
							if(c==0x0d){
								if(p[player].sp==5){
									if(player==0){								//attacker 必殺
										printf("\n必殺発動\n防御無視して%dダメージ\n",p[player].power+20);
										Sleep(100);
										printf("攻撃力+20\n");
										Sleep(100);
										printf("しかしHP -20\n");
										p[player].hp -= 20;
										if(p[player].charge!=0){
											p[player].power += 40;
										}
										else{
											p[player].power += 20;
										}
										p[enemy].hp = p[enemy].hp - p[player].power;
									}
									else if(player==1){							//gard man 必殺
										printf("\n必殺発動\n敵の防御力を-20して40回復\n");
										Sleep(100);
										printf("敵の防御力-20\n");
										p[enemy].gard -= 20;
										if(p[enemy].gard < 10)p[enemy].gard = 10;
										Sleep(100);
										printf("HP +20\n");
										p[player].hp += 20;
									}
									else if(player==2){							//collector 必殺
										printf("\n必殺発動\n空き枠があるとき2つまでアイテム追加\n");
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
													printf("まだ使うべきではないようだ\n");
													musi=1;
													break;
												}
											}
										}
									}
									if(musi==0){								//必殺使用後
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
									printf("\nまだ使えないよ\n");
									go=0;
									Sleep(300);
								}
							}
							else if(c=='q'){
								go=0;
							}
						}
						else{													//ステータス
							system("cls");
							printf("ステータス\n");
							if(p[player].know!=0){
								printf("HP : %.lf\n攻撃力 : %d\n守備力 : %d\n速さ　 : %d\n回避率 : %d\n知力　 : %d",p[player].hp,p[player].power,p[player].gard,p[player].speed,p[player].dodge,p[player].know);
							}
							else{
								printf("HP : %.lf\n攻撃力 : %d\n守備力 : %d\n速さ　 : %d\n回避率 : %d\n",p[player].hp,p[player].power,p[player].gard,p[player].speed,p[player].dodge);
							}
							printf("\n\nEnemy\nHP : %.lf\n攻撃力 : %d\n守備力 : %d\n速さ　 : %d\n回避率 : %d\n",p[enemy].hp,p[enemy].power,p[enemy].gard,p[enemy].speed,p[enemy].dodge);
							getche();
						}
					}while(go!=1);
					if(p[player].sp!=5){										//ゲージ上昇
						p[player].sp+=1;
					}
					if(p[player].charge!=0){									//item rebirth ターン経過処理
						p[player].charge+=1;
						if(p[player].charge==4){
							p[player].power = p[player].power/2;
							p[player].charge=0;
						}
					}
					if(p[player].turnlimit>0){									//item doping ターン経過処理
						p[player].turnlimit-=1;
						if(p[player].turnlimit==0){
							p[player].power -= 10;
							p[player].turnlimit=0;
						}
					}
					turn=0;
					Sleep(1000);
				}
				else{															//enemyターン
					if(p[player].uramiti==3){
						if(ptry==0)printf("Enemy : ...何のつもりだ？\n");
						else if(ptry==1)printf("Enemy : ...もう一度ってか?\n");
						else printf("Enemy : 懲りないな\n");
						Sleep(1000);
					}
					else if(p[player].uramiti==4){
						if(ptry==0)printf("Enemy : ハハハハ、面白いやつだな\n　　　　いいだろう、お前の知識を試してやる\n");
						else if(ptry==1)printf("Enemy : 今度はがっかりさせるなよ...?\n");
						else printf("Enemy : おとなしく攻撃してればいいものを...\n");
						p[player].uramiti=0;
						p[player].know=0;
						Sleep(1000);
						printf("Enemyが問題を出してきた\n\n");
						END=end();
						reset();
						if(END==1){
							p[enemy].hp -= 700;
							if(ptry==0)printf("Enemy : やるな...その知識量に感服した\n　　　　俺の負けだ、これからも精進することだな...\n");
							else if(ptry==1)printf("Enemy : なんだ、隠してたのか...\n　　　　だがまだ爪が...甘..い....な.....\n");
							else printf("Enemy : 何回もプレイした成果か?\n　　　　それとも製作者がばらしたか...\n　　　　腑に落ちねーが今回は負けといてやる\n");
							Sleep(1000);
						}
						else {
							if(ptry==0)printf("Enemy : なんだ、その程度か...\n　　　　拍子抜けだな...!\n\n");
							else if(ptry==1)printf("Enemy : 無理せず武力に染まってろ\n");
							else printf("Enemy : 平和はあきらめろ\n");
							printf("敵は必殺技を発動しようとしている...\n");
							p[enemy].sp = 1;
							ptry++;
							Sleep(1000);
						}
					}
					else{
						printf("相手の攻撃\n");
						enemysel = rand()%4+1;										//攻撃選択
						kaihi = rand()%1000+1;
						if(kaihi<=p[player].dodge){
							printf("かわした\n");
						}
						else if(p[enemy].sp==1){
							printf("邪悪なオーラが敵を覆っている...\n");
							p[enemy].sp = 2;
							Sleep(1000);
						}
						else if(p[enemy].sp==2){
							printf("敵は必殺技『唯我独尊』を繰り出した\n");
							printf("100ダメージくらった!!\n");
							p[player].hp -= 100;
							Sleep(100);
							printf("全ステータスが-20された!!\n");
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
							if(100*p[enemy].hp / 700 <= 30){						//体力30%以下
								if(up3==0){
									printf("最後の力\n攻撃力+%d × 2\n",p[player].power);
									p[enemy].power += p[player].power * 2;
									up3=1;											//1回限り
								}
								else{
									pattern=enemysel;								//通常パターン
								}
							}
							else if(100*p[enemy].hp / 700 <= 40){					//体力40%以下
								if(up2==0){
									printf("相手は逃げ腰になった\n攻撃力-20   回避力+20\n");
									p[enemy].power -= 20;
									p[enemy].dodge += 20;
									up2=1;
								}
								else{
									pattern=enemysel;
								}
							}
							else if(100*p[enemy].hp / 700 <= 60){					//体力60%以下
								if(up1==0){
									printf("相手は身を守った\n防御力+30\n");
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
							if((pattern==2)&&(p[player].turnlimit>0)){				//下段重複防止
								pattern=1;
							}
							if((pattern==1) || (pattern==3)){						//ただの攻撃
								damage=p[enemy].power*10/p[player].gard;
								if(10>damage)damage=10;
								p[player].hp -= damage;
								printf("%.lfダメージ\n",damage);
							}
							else if(pattern==2){									//下段蹴り
								printf("下段蹴り(卑怯)\nあなたは足を痛めた\n");
								p[player].hp -= 10;
								p[player].turnlimit2 = 3;
								printf("10ダメージ\n");
							}
							else if(pattern==4){									//正拳突き
								printf("正拳突き\n");
								damage=p[enemy].power*2*10/p[player].gard;
								if(10>damage)damage=10;
								p[player].hp -= damage;
								printf("%.lfダメージ\n",damage);
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
		for(int def=0;def<NUM;def++){											//フラグ初期化
			q[def].flag=0;
		}
		modosu();
		up1=up2=up3=0;
		debug = 0;
		re++;
	}
	return 0;
}

