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

// ���ڿ��� �ؽõ����ͷ� ��ȯ
unsigned hash(char *s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;

	return hashval % HASHSIZE;
}

// �ؽ� ���̺� s�� Ž�� ������ ��� ��� ����ü �����͸� ��ȯ, ���� ��� null�� ��ȯ
struct nlist* lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;
	return NULL;
}

// ��
char *str_mcopy(char *s)
{
	char *p;
	p = (char *)malloc(strlen(s) + 1);
	if (p != NULL)
		strcpy(p, s);
	return p;
}


// ������ ����
struct nlist* install(char *name, char *phone)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {			// lookup���� �ؽ����̺� �� ���� ����Ǿ� �ִ��� Ȯ���ϰ� ������ null ��, ÷�ö��� �̰� ����
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = str_mcopy(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;

	}
	else //	����
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

	char *name[] = { "�ճ���","������","������",
					"��ä��","������","��ä��" };
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
	ptr = lookup("��ä��");

	while (ptr != NULL)
	{
		printf("found: %s, %s\n", ptr->name, ptr->phone);
		ptr = ptr->next;
	}
	
	printf("\nPress any key to end...");
	getchar();
	return 0;
}