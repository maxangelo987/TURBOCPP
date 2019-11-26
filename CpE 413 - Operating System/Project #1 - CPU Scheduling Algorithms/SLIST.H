#ifndef slist
#define slist

#include<conio.h>
#include<stdio.h>
//#include<iostream.h>

template <class Name, class Atime>
class mylist
{
public:
mylist();
~mylist();
mylist *create_list(Name&, Atime&, Atime&, Atime&);
void insert_beginning(Name&, Atime&, Atime&, Atime&);
void insert_last(Name&, Atime&, Atime&, Atime&);
void delete_node();
void update_node(Atime&, Atime&, long);
void sortlist(int);
void display();
int check_btime();
Name *access_namelist();
Atime *access_atimelist();
Atime *access_btimelist();
Atime *access_prioritylist();
long accs_totnumlist();

Name arr_name,*listname,rev3;
Atime arr_atime,arr_btime,arr_priority,*listatime,*listbtime,*listpriority,rev,rev2,rev4;

mylist  *start, *next, *prev, *temp, *s, *p, *t;
};
//------------------------------------
template <class Name, class Atime>
mylist<Name,Atime>::mylist(){
start=NULL;
}
//------------------------------------
template <class Name, class Atime>
mylist<Name,Atime>::~mylist(){
delete [] listname;
delete [] listatime;
delete [] listbtime;
delete [] listpriority;

}
//------------------------------------

template <class Name, class Atime>
mylist<Name,Atime>* mylist<Name,Atime>::create_list(Name& name, Atime &atime,  Atime &btime,  Atime &priority){
temp=new mylist;

if(temp==NULL){
	      printf("Memory not allocated");
	      return 0;
	      }
else{
	temp->arr_name=name;
	temp->arr_atime=atime;
	temp->arr_btime=btime;
	temp->arr_priority=priority;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
	}
}
//------------------------------------

template <class Name, class Atime>
void mylist<Name,Atime>::insert_beginning(Name& name, Atime &atime,  Atime &btime,  Atime &priority){
	temp=create_list(name, atime, btime, priority);
	if(start==NULL){
		start=temp;
		start->next=NULL;
		return;
	}
	else{
	s=start;
	start=temp;
	start->next=s;
	return;
	}
}
//------------------------------------
template <class Name, class Atime>
void mylist<Name,Atime>::insert_last(Name& name, Atime &atime,  Atime &btime,  Atime &priority){

temp=create_list(name, atime, btime, priority);
	if(start==NULL){
	       start=temp;
	       start->next=NULL;
		   start->prev=NULL;
	       return;
	}
	else{
	s=start;
		while(s->next!=NULL){
			s=s->next;
			}
	s->next=temp;
	temp->next=NULL;
	temp->prev=s;
	return;
	}

}
//------------------------------------
template <class Name, class Atime>
void mylist<Name,Atime>::delete_node(){
}
//------------------------------------
template <class Name, class Atime>
void mylist<Name,Atime>::display(){
	if(start==NULL){
	printf("Empty");
	return;
	}
	else{
	temp=start;
	while(temp!=NULL){
		cout<<temp->arr_name<<" "<<temp->arr_atime<<" "<<temp->arr_btime<<" ";
		temp=temp->next;
		}

	}
}
//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------

//------------------------------------
template<class Name, class Atime>
Name* mylist<Name,Atime>::access_namelist(){
	listname=new Name[accs_totnumlist()];
	long a=0;
	temp=start;
	while(temp!=NULL){
		listname[a]=temp->arr_name;
		a++;
		temp=temp->next;
		}
		return listname;
}
//------------------------------------
template<class Name, class Atime>
Atime* mylist<Name,Atime>::access_atimelist(){
	listatime=new Atime[accs_totnumlist()];
	long a=0;
	temp=start;
	while(temp!=NULL){
		listatime[a]=temp->arr_atime;
		a++;
		temp=temp->next;
		}
		return listatime;
}
//------------------------------------

//------------------------------------
template<class Name, class Atime>
Atime* mylist<Name,Atime>::access_btimelist(){
	listbtime=new Atime[accs_totnumlist()];
	long a=0;
	temp=start;
	while(temp!=NULL){
		listbtime[a]=temp->arr_btime;
		a++;
		temp=temp->next;
		}
		return listbtime;
}
//------------------------------------
//------------------------------------
template<class Name, class Atime>
Atime* mylist<Name,Atime>::access_prioritylist(){
	listpriority=new Atime[accs_totnumlist()];
	long a=0;
	temp=start;
	while(temp!=NULL){
		listpriority[a]=temp->arr_priority;
		a++;
		temp=temp->next;
		}
		return listpriority;
}
//------------------------------------

template<class Name, class Atime>
long mylist<Name, Atime>::accs_totnumlist(){
temp=start;
long mycount=0;
while(temp!=NULL){
	temp=temp->next;
	mycount++;
	}
	return mycount;
}
//-----------------------------------
template<class Name, class Atime>
void mylist<Name, Atime>::update_node(Atime& newitem, Atime& newitem2, long pos){
	long z;
	if(start==NULL){
		cout<<"Empty";
		return;
	}
	else{
		temp=start;
		z=1;
		while(temp!=NULL){
			if(pos==z){
				temp->arr_atime=newitem;
				temp->arr_btime=newitem2;
				return;
			}
			z++;
			temp=temp->next;
		}
	}

}
//------------------------------------
template<class Name, class Atime>
void mylist<Name, Atime>::sortlist(int cond){
	int count_atime=0;
	if(start==NULL){
	    cout<<"Empty";
	    return;
	}
	else{

	  switch(cond){
	  case 1:
		s=start;

		while(s!=NULL){
		temp=start;
		     while(temp->next!=NULL){
			if(temp->arr_priority>temp->next->arr_priority){
			    rev=temp->arr_priority;
			    rev2=temp->arr_btime;
			    rev3=temp->arr_name;

			    temp->arr_priority=temp->next->arr_priority;
			    temp->arr_btime=temp->next->arr_btime;
			    temp->arr_name=temp->next->arr_name;

			    temp->next->arr_priority=rev;
			    temp->next->arr_btime=rev2;
			    temp->next->arr_name=rev3;
			}
			temp=temp->next;
		      }
		    s=s->next;
		    }

		break;
	  case 2:
		s=start->next;
		while(s->next!=NULL){
		    for(temp=s->next; temp!=NULL; temp=temp->next){
			
			count_atime=0;
			for(t=start; t<s; t=t->next){
				count_atime+=t->arr_btime;
			}
		//	cout<<s->arr_btime <<" "<< temp->arr_btime;
			if(s->arr_btime > temp->arr_btime && temp->arr_atime <= count_atime){
			   
				rev=temp->arr_atime;
			    rev2=temp->arr_btime;
			    rev3=temp->arr_name;
				
				for(p=temp; p>s; p=p->prev){
				
			    p->arr_atime=p->prev->arr_atime;
			    p->arr_btime=p->prev->arr_btime;
			    p->arr_name=p->prev->arr_name;
											}
			    s->arr_atime=rev;
			    s->arr_btime=rev2;
			    s->arr_name=rev3;
			    }
		      }
		    s=s->next;
		    }
		break;

	  case 3:
		s=start;
		while(s->next!=NULL){
		    for(temp=s->next; temp!=NULL; temp=temp->next){
			
			count_atime=0;
			for(t=start; t<s; t=t->next){
				count_atime+=t->arr_btime;
			}
		//	cout<<s->arr_btime <<" "<< temp->arr_btime;
			if(s->arr_btime > temp->arr_btime){
			   
				rev=temp->arr_atime;
			    rev2=temp->arr_btime;
			    rev3=temp->arr_name;
				
				for(p=temp; p>s; p=p->prev){
				
			    p->arr_atime=p->prev->arr_atime;
			    p->arr_btime=p->prev->arr_btime;
			    p->arr_name=p->prev->arr_name;
											}
			    s->arr_atime=rev;
			    s->arr_btime=rev2;
			    s->arr_name=rev3;
			    }
		      }
		    s=s->next;
		    }
		break;
	  default:   break;

	    }
	  }
}

template<class Name, class Atime>
int mylist<Name, Atime>::check_btime(){
temp=start;
while(temp!=NULL){
	if(temp->arr_btime!=0){
	return 1;
	}
	else{
	// just do nothing
	}
	temp=temp->next;
	}
	return 0;
}


#endif