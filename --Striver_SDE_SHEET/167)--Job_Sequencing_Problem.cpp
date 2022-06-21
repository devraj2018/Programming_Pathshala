static bool compare(vector<int> &job1, vector<int> &job2) 
   { return job1[1] > job2[1];}
 
int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);
     int maxProfit = 0;
    int maxDeadline = 0;
    for (int i = 0; i < jobs.size(); i++) maxDeadline = max(maxDeadline, jobs[i][0]);
   

    
    bool slots[maxDeadline + 1];
    for (int i = 0; i <= maxDeadline; i++) slots[i] = false;
   
    for (int i = 0; i < jobs.size(); i++)
      {
        for (int j = jobs[i][0]; j > 0; j--)
          {

            if (slots[j] == false)
            {
                maxProfit = maxProfit + jobs[i][1];
                slots[j] = true;
                break;
            }
        }
    }

    return maxProfit;
}
