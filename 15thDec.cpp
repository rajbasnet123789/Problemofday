/*1792. Maximum Average Pass Ratio
Solved
Medium
Topics
Companies
Hint
There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.
*/
// Brute force
 double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        vector<double> PR(n);

        // Calculate initial pass ratios for all classes
        for (int i = 0; i < n; i++) {
            PR[i] = (double)classes[i][0] / classes[i][1];
        }

        // Distribute all extra students
        while (extraStudents--) {
            int bestClass = -1;
            double maxDelta = 0.0;

            // Find the class with the maximum improvement (delta)
            for (int i = 0; i < n; i++) {
                int pass = classes[i][0];
                int total = classes[i][1];
                double currentRatio = (double)pass / total;
                double newRatio = (double)(pass + 1) / (total + 1);
                double delta = newRatio - currentRatio;

                if (delta > maxDelta) {
                    maxDelta = delta;
                    bestClass = i;
                }
            }

            // Update the chosen class with an extra student
            classes[bestClass][0]++;
            classes[bestClass][1]++;
            PR[bestClass] = (double)classes[bestClass][0] / classes[bestClass][1];
        }

        // Calculate the final result
        double result = 0.0;
        for (int i = 0; i < n; i++) {
            result += PR[i];
        }

        return result / n;
    }


//Optimal 
 double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
  int n = classes.size();
        priority_queue<pair<double, int>> pq;

        // Initial pass ratios and deltas
        for (int i = 0; i < n; i++) {
            double curr_PR = (double)classes[i][0] / classes[i][1];
            double new_PR = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            double delta = new_PR - curr_PR;
            pq.push({delta, i}); // Push improvement delta and class index
        }

        // Allocate extra students
        while (extraStudents--) {
            auto curr = pq.top();
            pq.pop();
            int idx = curr.second;

            // Update the chosen class
            classes[idx][0]++;
            classes[idx][1]++;

            // Recompute delta for the updated class
            double curr_PR = (double)classes[idx][0] / classes[idx][1];
            double new_PR = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            double delta = new_PR - curr_PR;

            // Push updated delta and index back into the queue
            pq.push({delta, idx});
        }

        // Calculate the final average pass ratio
        double result = 0.0;
        for (int i = 0; i < n; i++) {
            result += (double)classes[i][0] / classes[i][1];
        }

        return result / n;
    }



   



 