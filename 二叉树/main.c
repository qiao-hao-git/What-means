#include <stdio.h>
#include <stdlib.h>
//查找
//递归
Position Find(int X,BinTree BST){
    if(!BST){
        return NULL:
    }
    if(X>BST->Data){
        return FInd(X,BST->Right);
    }
    else if(X<BST->Data){
        return FInd(X,BST->Left);
    }
    else{
        return BST;
    }
}
//非递归
Position IterFind(int X,BinTree BST){
    while(BST){
        if(X>BST->Data){
            BST=BST->Right;
        }
        else if(X<BST->Data){
            BST=BST->Left;
        }
        else{
            return BST;
        }
    }
    return NULL:
}
//最小值
Position FindMIn(BinTree BST){
    if(!BST){
        return NULL:
    }
    else if(!BST->Left){
        return BST;
    }
    else{
        return FindMin(BST->Left);
    }
}
//最大值
Position FindMax(BinTree BST){
   if(BST){
        while(BST->Right){
            BST=BST->Right;
        }
   }
   return BST;
}
//插入
BinTree Insert(int X,BinTree BST){
    if(!BST){
        BST=malloc(sizeof(struct TreeNode));
        BST->Data=X;
        BST->Left=BST->Right=NULL;
    }
    else{
        if(X<BST->Data){
            BST->Left=Insert(X,BST->Left);
        }
        else if(X>BST->Data){
            BST->Right=Insert(X,BST->Right);
        }
    }
    return BST;
}
//删除
BinTree Delete(int X,BinTree BST){
    Position Tmp;
    if(!BST){
        printf("没有要删除的元素");
    }
    else if(X<BST->Data){
        BST->Left=Delete(X,BST->Left);
    }
    else if(X>BST->Data){
        BST->Right=Delete(X,BST->Right);
    }
    else{
        if(BSt->Left&&BST->Right){
            Tmp=FindMin(BST->Right);
            BST->Data=Tmp->Data;
            BST->Right=Delete(BST->Data,BST->Right);
        }
        else{
            Tmp=BST;
            if(!BST->Left){
                BST=BST->Right;
            }
            else if(!BST->Right){
                BST=Tmp->Letf;
            }
            free(Tmp);
        }
    }
    return BST;
}
//平衡二叉树
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode{
    int Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};
int Max(int a,int b){
    return a>b?a:b;
}
AVLTree SingleLeftRotation(AVLTree A){
    AVLTree B=A->Left;
    A->Left=B->Right;
    B->Right=A;
    A->Height=Max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height=Max(GetHeight(B->Left),GetHeight(A->Height))+1;
    return B;
}
AVLTree DoubleLeftRightRotation(AVLTree A){
    A->Left=SingleLeftRotation(A->Left);
    return SingleLeftRotation(A);
}
AVLTree Insert(AVLTree T,int X){
    if(!T){
        T=(AVLTree)malloc(sizeof(struct AVLNode));
        T->Data=X;
        T->Height=0;
        T->Left=T->Right=NULL;
    }
    else if(X<T->Data){
        T->Left=Insert(T->Left,X);
        if(GetHeight(T->Left)-GetHeight(T->Right)==2){
            if(X<T->Left->Data){
                T=SingleLeftRotation(T);
            }
            else{
                T=DoubleLeftRightRotation(T);
            }
        }
    }
    else if(X>T->Data){
        T->Right=Insert(T->Right,X);
        if(GetHeight(T->Right)-GetHeight(T->Left)==2){
            if(X>T->Right->Data){
                T=SingleRightRotation(T);
            }
            else{
                T=DoubleRightLeftRotation
            }
        }
    }
    T->Height=Max(GetHeight(T->Left),GetHeight(T->Right))+1;
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
