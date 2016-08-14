import java.util.Arrays;

class HungarianAlgorithm {
    private final double[][] costMatrix;
    private final int N, rows, columns;

    private final double[] labelByWorker, labelByJob;
    private final int[] matchJobByWorker, matchWorkerByJob;

    private final boolean[] committedWorkers;
    private final int[] workerByCommittedJob;

    private final double[] minSlackValueByJob;
    private final int[] minSlackWorkerByJob;

    HungarianAlgorithm(double[][] costMatrix){
        this.N = Math.max(costMatrix.length, costMatrix[0].length);
        this.rows = costMatrix.length;
        this.columns = costMatrix[0].length;
        this.costMatrix = new double[this.N][this.N];

        for (int w = 0; w < this.N; w++)
            if (w < costMatrix.length){
                if (costMatrix[w].length != this.columns)
                    throw new IllegalArgumentException("Irregular cost matrix!");

                this.costMatrix[w] = Arrays.copyOf(costMatrix[w], this.N);
            }
            else
                this.costMatrix[w] = new double[this.N];

        labelByWorker = new double[this.N];
        labelByJob = new double[this.N];

        committedWorkers = new boolean[this.N];
        workerByCommittedJob = new int[this.N];

        minSlackValueByJob = new double[this.N];
        minSlackWorkerByJob = new int[this.N];

        matchJobByWorker = new int[this.N];
        Arrays.fill(matchJobByWorker, -1);
        matchWorkerByJob = new int[this.N];
        Arrays.fill(matchWorkerByJob, -1);
    }

    private void reduce(){
        for (int w = 0; w < N; w++) {
            double min = Double.POSITIVE_INFINITY;

            for (int j = 0; j < N; j++)
                min = Math.min(min, costMatrix[w][j]);

            for (int j = 0; j < N; j++)
                costMatrix[w][j] -= min;
        }

        double[] min = new double[N];
        Arrays.fill(min, Double.POSITIVE_INFINITY);

        for (int w = 0; w < N; w++)
            for (int j = 0; j < N; j++)
                min[j] = Math.min(min[j], costMatrix[w][j]);

        for (int w = 0; w < N; w++)
            for (int j = 0; j < N; j++)
                costMatrix[w][j] -= min[j];
    }

    private void computeInitialFeasibleSolution(){
        Arrays.fill(labelByJob, Double.POSITIVE_INFINITY);

        for (int w = 0; w < N; w++)
            for (int j = 0; j < N; j++)
                labelByJob[j] = Math.min(labelByJob[j], costMatrix[w][j]);
    }

    private void match(int w, int j){
        matchJobByWorker[w] = j;
        matchWorkerByJob[j] = w;
    }

    private void greedyMatching(){
        for (int w = 0; w < N; w++)
            for (int j = 0; j < N; j++)
                if (matchJobByWorker[w] == -1 && matchWorkerByJob[j] == -1 &&
                        costMatrix[w][j] - labelByJob[j] - labelByWorker[w] == 0)
                    match(w, j);
    }

    private int getUnmatchedWorker(){
        int w = 0;

        while (w < N && matchJobByWorker[w] != -1)
            w++;

        return w;
    }

    private void updateLabeling(double slack){
        for (int w = 0; w < N; w++)
            if (committedWorkers[w])
                labelByWorker[w] += slack;

        for (int j = 0; j < N; j++) {
            if (workerByCommittedJob[j] != -1)
                labelByJob[j] -= slack;
            else
                minSlackValueByJob[j] -= slack;
        }
    }

    private void initializePhase(int w){
        Arrays.fill(committedWorkers, false);
        Arrays.fill(workerByCommittedJob, -1);

        committedWorkers[w] = true;

        for (int j = 0; j < N; j++) {
            minSlackValueByJob[j] = costMatrix[w][j] - labelByJob[j] - labelByWorker[w];
            minSlackWorkerByJob[j] = w;
        }
    }

    private void executePhase(){
        while (true){
            int minSlackWorker = -1, minSlackJob = -1;
            double minSlackValue = Double.POSITIVE_INFINITY;

            for (int j = 0; j < N; j++)
                if (workerByCommittedJob[j] == -1){
                    if (minSlackValueByJob[j] < minSlackValue){
                        minSlackValue = minSlackValueByJob[j];
                        minSlackWorker = minSlackWorkerByJob[j];
                        minSlackJob = j;
                    }
                }

            if (minSlackValue > 0)
                updateLabeling(minSlackValue);

            workerByCommittedJob[minSlackJob] = minSlackWorker;

            if (matchWorkerByJob[minSlackJob] == -1){
                int committedJob = minSlackJob;
                int worker = workerByCommittedJob[committedJob];

                while (true){
                    int tmp = matchJobByWorker[worker];
                    match(worker, committedJob);
                    committedJob = tmp;

                    if (committedJob == -1)
                        break;

                    worker = workerByCommittedJob[committedJob];
                }

                return;
            }
            else{
                int worker = matchWorkerByJob[minSlackJob];
                committedWorkers[worker] = true;

                for (int j = 0; j < N; j++)
                    if (workerByCommittedJob[j] == -1){
                        double slack = costMatrix[worker][j] - labelByWorker[worker] - labelByJob[j];

                        if (minSlackValueByJob[j] > slack){
                            minSlackValueByJob[j] = slack;
                            minSlackWorkerByJob[j] = worker;
                        }
                    }
            }
        }
    }

    public int[] execute(){
        reduce();
        computeInitialFeasibleSolution();
        greedyMatching();

        int w = getUnmatchedWorker();
        while (w < N){
            initializePhase(w);
            executePhase();
            w = getUnmatchedWorker();
        }

        int[] answer = Arrays.copyOf(matchJobByWorker, this.rows);

        for (w = 0; w < answer.length; w++)
            if (answer[w] >= this.columns)
                answer[w] = -1;

        return answer;
    }
}