#include<stdio.h>
#include<string.h>
#define READY 1//�^�X�N���L���[���痣��Ă���
#define RUN 2//�^�X�N���L���[�Ɍq�����Ă���
//�v���g�^�C�v�錾
int funcA(void);
int funcB(void);
int funcC(void);
void set(void);
struct TCB{//�\���̐錾
	int id;//�v���Z�Xid
	int state;//���
	struct TCB *next;//�\���ϐ��錾
	int (*task)();//�֐��|�C���^	
}tcb[3];//�\���̔z��
void put(struct TCB *puttcb);
void get(struct TCB *gettcb,struct TCB *getqtcb);

int main(void){
	struct TCB *nowtcb,*qtcb,*dqtcb;//�\���̃|�C���^	
	int count;//���X�g��
	set();//�֐�������
	nowtcb=&tcb[0];//�A�h���X�̎w��
	for(count=0;count<5;count++){//0~4�ł���
		nowtcb->task();//�֐��̌Ăяo��
		dqtcb=nowtcb;//�g�p����߲��
		nowtcb=nowtcb->next;//���ֈڍs
		qtcb=nowtcb;//�Ō�̃|�C���^
		while(NULL!=qtcb->next){//�Ō�܂ł̒T��
			qtcb=qtcb->next;//�Ō���߲���ۑ�
		}
		put(dqtcb);//���������|�C���^�����
		get(dqtcb,qtcb);//�|�C���^���Ȃ���
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
	tcb[0].id=0;//�v���Z�X�ԍ�
	tcb[0].state=RUN;//���
	tcb[0].task=funcA;//�֐�����
	tcb[0].next=&tcb[1];//�|�C���^�w��
	tcb[1].id=1;
	tcb[1].state=RUN;
	tcb[1].task=funcB;
	tcb[1].next=&tcb[2];
	tcb[2].id=2;
	tcb[2].state=RUN;
	tcb[2].task=funcC;
	tcb[2].next=NULL;
}
int funcA(void){//�֐�
	printf("funcA()\r\n");	//�����̏o��
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