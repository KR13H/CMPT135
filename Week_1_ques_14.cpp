/* 14. Write a function named getTopStudentRecord that takes two arguments: a dynamic array of structs of 
type StudentRecord and its size and then returns the element of the array whose total mark is the 
maximum. If there are more than elements with the same maximum marks, return just any one of them.
 */
StudentRecord getTopStudentRecord(const StudentRecord* a, const int size)
{
	StudentRecord top_student;
	// int total = test*0.2 + midterm*0.3 + final*0.5;
	int tmax = a[0].test * 0.2 + a[0].midterm * 0.3 + a[0].final * 0.5;
	int max_index = 0;
	for(int i = 1; i < size; i++)
	{
		int total = a[i].test * 0.2 + a[i].midterm * 0.3 + a[i].final * 0.5;
		if(total > tmax)
			max_index = i;
	}
	top_student = a[max_index];
	return top_student;
}
