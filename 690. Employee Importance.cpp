class Solution {
public:
	/*struct Employee {
		int id;
		int importance;
		vector<int> subordinates;
	};*/
	int getImportance(vector<Employee*> employees, int id) {
		int count = 0;
		queue<int> queue;
		queue.push(id);
		int empId;
		Employee *emp = NULL;
		int size;
		while (!queue.empty())
		{
			empId = queue.front();
			queue.pop();
			emp = theEmp(employees, empId);
			count += emp->importance;
			for (int sub : emp->subordinates)
			{
				queue.push(sub);
			}
		}
		return count;
	}
	Employee *theEmp(vector<Employee*> &employees, int empId)
	{
		for (auto tempEmp : employees)
		{
			if (tempEmp->id == empId)
				return tempEmp;
		}
		return NULL;
	}
};