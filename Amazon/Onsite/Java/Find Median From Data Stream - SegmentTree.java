class Node {
    int start;
    int end;
    int value;
    Node left;
    Node right;
    public Node (int start, int end){
        this.start = start;
        this.end = end;
        this.value = 0;
    }
    public void add (int val){
        if (start <= val && val <= end){
            value ++;
        }
        else return;
        if (start == end) return;
        long middle = ((long)start) + (((long)end) - ((long)start)) / ((long) 2);
        int mid = (int) middle;
        if (val <= mid  && left == null){
            left = new Node (start, mid);
        }
        if (val >= mid + 1 && right == null){
            right= new Node (mid+1, end);
        }
        if (left!= null) left.add(val);
        if (right!=null) right.add(val);        
    }
    public double query(int k){
        if (start == end) return (double)start;
        if (left!=null && right!=null){
            if (k <= left.value){return left.query(k);}
            else if (k > left.value){
                return right.query(k - left.value);
            }
            return 0.0;
        }
        if (left == null) return right.query(k);
        if (right == null) return left.query(k);
        return 0.0;
    }
}

class MedianFinder {
    Node root;
    int size = 0;
    /** initialize your data structure here. */
    public MedianFinder() {
        root = new Node (Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
    
    public void addNum(int num) {
        root.add(num);
        size++;
    }
    
    public double findMedian() {
        return (root.query((size+1 )/2) + root.query((size+2)/2)) / 2.0;
    }
}

