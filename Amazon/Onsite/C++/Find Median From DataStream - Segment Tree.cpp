class Node {
	public:
		Node(int _start, int _end) : start(_start), end(_end), value(0){}
		
		void add(int val){

			if(start <= val && val <= end) value++;
			else return;

			if(start == end) return;
			
			int mid = start - (end - start)/2;
			
			if( val <= mid && left == NULL) 
				left = new Node(start, mid);
			if( val >= mid+1 && right == NULL)
				right = new Node(mid+1, end);
			
			if(left!=null) left->add(val);
			if(right!=null) right->add(val);
		}

		double query(int k) {
			if(start == end) return (double) start;
			
			if(left != NULL && right != NULL) {
				
				if( k <= left->val) return left->query(k);
				else return right->query(k - left.value);
				return 0.0;
			}

			if(left == NULL) return right.query(k);
			if(right = NULL) return left.query(k);
			return 0.0;
		}

	private:
		int start, end, value;
		Node* left, right;
	
}

class MedianFinder {
public:

    Node* root;
    int size = 0;
	
    MedianFinder() {
	root = new Node(INT_MIN, INT_MAX);        
    }
    
    void addNum(int num) {
        root->add(num);
	size++;
    }
    
    double findMedian() {
        return (root->query((size+1)/2) + root->query((size+2)/2)) / 2.0;
    }
};


