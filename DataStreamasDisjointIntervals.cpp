// 二叉搜索树
// set
// 注意仿函数的定义

struct comp { 
	bool operator() (const Interval& a, const Interval& b) { 
		return a.end < b.start; 
	}
};

class SummaryRanges {
public:
	/** Initialize your data structure here. */
	SummaryRanges() {
	}

	void addNum(int val) {
		Interval i(val, val);

		set<Interval, comp>::iterator l = rbtree.lower_bound(i);
		set<Interval, comp>::iterator r = rbtree.upper_bound(i);

		if (l == r) { // 不在已知区间中
			if (!rbtree.empty()) { // 非空区间
				--l;
				int start = val;
				int end = val;
				
				if (l != rbtree.end() && r != rbtree.end() && l->end + 1 == val && val + 1 == r->start) { // 合并左右区间
					start = l->start;
					end = r->end;
					rbtree.erase(l);
					rbtree.erase(r);
				}
				else if (r != rbtree.end() && val + 1 == r->start) { // 合并右区间
					start = val;
					end = r->end;
					rbtree.erase(r);
				}
				else if (l != rbtree.end() && l->end + 1 == val) { // 合并左区间
					start = l->start;
					end = val;
					rbtree.erase(l);
				}
			
				rbtree.insert(Interval(start, end));
			}
			else { // 空区间
				rbtree.insert(Interval(val, val));
			}
		}

		return;
	}

	vector<Interval> getIntervals() {
		vector<Interval> rel;
		for (set<Interval, comp>::iterator itr = rbtree.begin(); itr != rbtree.end(); ++itr) {
			rel.push_back(Interval(itr->start, itr->end));
		}
		return rel;
	}

private:
	set<Interval, comp> rbtree;
};