#include<stdio.h>
#include<string.h>
//�v���g�^�C�v�錾
int funcA(void);
int funcB(void);
int funcC(void);
void set(void);
struct TCB{//�\���̐錾
	struct TCB *next;//�\���ϐ��錾
	int (*task)();//�֐��|�C���^	
}tcb[3];//�\���̔z��
int main(void){
	struct TCB *nowtcb;//�\���̃|�C���^	
	int count;//���X�g��
	set();//�֐�������
	nowtcb=&tcb[0];//�A�h���X�̎w��
	for(count=0;count<3;count++){//0~2�ł���
		nowtcb->task();//�֐��̌Ăяo��
		nowtcb=nowtcb->next;//���ֈڍs
	}
			
}
void set(void){
	tcb[0].task=funcA;//�֐�����
	tcb[0].next=&tcb[1];//�|�C���^�w��
	tcb[1].task=funcB;
	tcb[1].next=&tcb[2];
	tcb[2].task=funcC;
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