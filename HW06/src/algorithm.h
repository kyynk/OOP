#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "alcohol.h"
#include "bits/stdc++.h"
using namespace std;

bool cp_name(Alcohol* a, Alcohol* b){
	return a->get_name() < b->get_name();
}

bool cp_content(Alcohol* a, Alcohol* b){
	if (a->get_alcohol_content() == b->get_alcohol_content())
		return cp_name(a, b);
	return a->get_alcohol_content() < b->get_alcohol_content();
}

void sort_alcohol_by_content(vector<Alcohol*> &alcohol){
	sort(alcohol.begin(), alcohol.end(), cp_content);
	// for (int i=0; i<alcohol.size(); i++){
	//     cout << alcohol[i]->get_alcohol_content() << alcohol[i]->get_name() << endl;
	// }
}

void sort_alcohol_by_name(vector<Alcohol*> &alcohol){
	sort(alcohol.begin(), alcohol.end(), cp_name);
	// for (int i=0; i<alcohol.size(); i++){
	// 	cout << alcohol[i]->get_alcohol_content() << alcohol[i]->get_name() << endl;
	// }
}

Alcohol* get_greatest_content_of_alcohol(vector<Alcohol*> alcohol){
	return *max_element(alcohol.begin(), alcohol.end(), cp_content);
}

Alcohol* get_smallest_content_of_alcohol(vector<Alcohol*> alcohol){
	return *min_element(alcohol.begin(), alcohol.end(), cp_content);
}
#endif