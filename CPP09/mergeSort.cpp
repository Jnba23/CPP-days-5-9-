#include <iostream>
#include <vector>

void merge(std::vector<int> lv, std::vector<int> rv, std::vector<int>& v){
	int l_size = v.size() / 2;
	int r_size = v.size() - l_size;
	int o = 0, l_idx = 0, r_idx = 0;
	while (l_idx < l_size && r_idx < r_size){
		if (lv[l_idx] < rv[r_idx]){
			v[o] = lv[l_idx];
			o++;
			l_idx++;
		}
		if (lv[l_idx] > rv[r_idx]){
			v[o] = rv[r_idx];
			o++;
			r_idx++;
		}
	}
	while (l_idx < l_size){
		v[o] = lv[l_idx];
		o++;
		l_idx++;
	}
	while (r_idx < r_size){
		v[o] = rv[r_idx];
		o++;
		r_idx++;
	}
}

void sortVec(std::vector<int>& v){
	if (v.size() <= 1)
		return ;
	std::vector<int> lv;
	std::vector<int> rv;
	lv.insert(lv.begin(), v.begin(), v.begin() + v.size() / 2);
	rv.insert(rv.begin(), v.begin() + v.size() / 2, v.end());
	sortVec(lv);
	sortVec(rv);
	merge(lv, rv, v);
}

int main(){
	std::vector<int> v;
	v.push_back(7);
	v.push_back(6);
	v.push_back(10);
	v.push_back(15);
	v.push_back(1);
	v.push_back(33);
	v.push_back(100);
	std::cout << "Before : ";
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << (it + 1 == v.end() ? "\n" : " ");
	}
	sortVec(v);
	std::cout << "After : ";
	for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
		std::cout << *it << (it + 1 == v.end() ? "\n" : " ");
	}
}