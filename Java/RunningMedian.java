import java.util.Comparator;
import java.util.PriorityQueue;

public class RunningMedian{
    private final PriorityQueue<Integer> minHeap = new PriorityQueue<>(Comparator.naturalOrder());
    private final PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

    public void addElement(int e){
        if (maxHeap.isEmpty() || e < maxHeap.peek())
            maxHeap.add(e);
        else
            minHeap.add(e);

        while (maxHeap.size() > minHeap.size() + 1){
            minHeap.add(maxHeap.remove());
        }

        while (minHeap.size() > maxHeap.size() + 1){
            maxHeap.add(minHeap.remove());
        }
    }

    public double median(){
        if (minHeap.isEmpty() && maxHeap.isEmpty())
            return 0;
        else if (minHeap.size() == maxHeap.size())
            return ((double)minHeap.peek() + maxHeap.peek()) / 2;
        else if (minHeap.size() > maxHeap.size())
            return minHeap.peek();
        else
            return maxHeap.peek();
    }
}
