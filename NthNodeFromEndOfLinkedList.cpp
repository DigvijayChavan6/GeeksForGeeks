//Find nth node form end of given linked list
class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
         int cnt=0,re=0;
         Node *p=head;
         while(p!=NULL){
             cnt++;
             p=p->next;
         }
         p=head;
         if(cnt-n<0)return -1;
         while(p!=NULL){
             if(cnt==n){
                 re=p->data;
                 break;
             }
             p=p->next;
             n++;
         }
         return re;
    }
};