#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

#define HASHSIZE 256

struct nlist {
	struct nlist *next;
	char *name;
	char *phone;
};

static struct nlist *hashtab[HASHSIZE];

// 문자열을 해시데이터로 변환
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

// 해시 테이블에 s를 탐색 존재할 경우 대상 구조체 포인터를 반환, 없을 경우 null을 반환
struct nlist* lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

// 뭐
char *str_mcopy(char *s)
{
	char *p;
	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}


// 데이터 삽입
struct nlist* install(char *name, char *phone)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {			// lookup으로 해시테이블에 그 값으 저장되어 있는지 확인하고 없으면 null 즉, 첨올때는 이거 실행
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = str_mcopy(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;

	}
	else //	기존
	{
		//-----------------------------
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = str_mcopy(name)) == NULL)
			return NULL;
		hashval = hash(name);
		//------------------------------
		struct nlist * pre_np = hashtab[hashval];
		while (pre_np->next != NULL)
			pre_np = pre_np->next;
		np->next = pre_np->next;
		pre_np->next = np;
		
		//-----------------------------
	}

	if ((np->phone = str_mcopy(phone)) == NULL)
		return NULL;

	return np;
}

int main()
{

	char *name[] = { "손나은","김태희","한지민",
					"문채원","전지현","문채원" };
	char *phone[] = { "731-1234", "567-8976", "521-5030",
					"521-9600", "418-4165", "520-3307", "425-1024" };
	int i, n = sizeof(name) / sizeof(name[0]);
	struct nlist *head, *ptr;


	for (i = 0; i < n; i++) {
		printf("%d: %s\n", hash(name[i]), name[i]);

		install(name[i], phone[i]);
	}

	printf("\nHash Table List \n");
	for (i = 0; i < HASHSIZE; i++) {
		head = hashtab[i];
		for (ptr = head; ptr != NULL; ptr = ptr->next) {
			printf("%d: %s, %s\n", i, ptr->name, ptr->phone);
		}
	}

	printf("\nHash Table Search \n");
	ptr = lookup("문채원");

	while (ptr != NULL)
	{
		printf("found: %s, %s\n", ptr->name, ptr->phone);
		ptr = ptr->next;
	}
	
	printf("\nPress any key to end...");
	getchar();
	return 0;
}