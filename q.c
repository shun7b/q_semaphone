#include<stdio.h>
#include<string.h>
#define READY 1//タスクがキューから離れている
#define RUN 2//タスクがキューに繋がっている
//プロトタイプ宣言
int funcA(void);
int funcB(void);
int funcC(void);
void set(void);
struct TCB{//構造体宣言
	int id;//プロセスid
	int state;//状態
	struct TCB *next;//構造変数宣言
	int (*task)();//関数ポインタ	
}tcb[3];//構造体配列
void put(struct TCB *puttcb);
void get(struct TCB *gettcb,struct TCB *getqtcb);

int main(void){
	struct TCB *nowtcb,*qtcb,*dqtcb;//構造体ポインタ	
	int count;//リスト数
	set();//関数初期化
	nowtcb=&tcb[0];//アドレスの指定
	for(count=0;count<5;count++){//0~4でする
		nowtcb->task();//関数の呼び出し
		dqtcb=nowtcb;//使用後のﾎﾟｲﾝﾀ
		nowtcb=nowtcb->next;//次へ移行
		qtcb=nowtcb;//最後のポインタ
		while(NULL!=qtcb->next){//最後までの探索
			qtcb=qtcb->next;//最後のﾎﾟｲﾝﾀ保存
		}
		put(dqtcb);//ｎｅｘｔポインタを取る
		get(dqtcb,qtcb);//ポインタをつなげる
	}	
}
void put(struct TCB *puttcb){
	puttcb->next=NULL;//nextpointer is NULL
	puttcb->state=READY;
	printf("%d\r\n",tcb->state);
}
void get(struct TCB *gettcb,struct TCB *getqtcb){
	getqtcb->next=gettcb;//get pointer
	gettcb->state=RUN;
	printf("%d\r\n",gettcb->state);
}
void set(void){
	tcb[0].id=0;//プロセス番号
	tcb[0].state=RUN;//状態
	tcb[0].task=funcA;//関数入力
	tcb[0].next=&tcb[1];//ポインタ指定
	tcb[1].id=1;
	tcb[1].state=RUN;
	tcb[1].task=funcB;
	tcb[1].next=&tcb[2];
	tcb[2].id=2;
	tcb[2].state=RUN;
	tcb[2].task=funcC;
	tcb[2].next=NULL;
}
int funcA(void){//関数
	printf("funcA()\r\n");	//文字の出力
	printf("7bjk1101\r\n");
}
int funcB(void){
	printf("funcB()\r\n");
	printf("inoue shunnsuke\r\n");
}
int funcC(void){
	printf("funcC()\r\n");
	printf("2019/10/17\r\n");
}