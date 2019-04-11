extern int passbook;	//외부 전역변수 

int get_bank()
{
	return passbook;
}

void set_bank()
{
	passbook++;
}
