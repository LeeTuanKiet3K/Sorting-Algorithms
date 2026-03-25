#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <cctype>
#include <vector>
using namespace std;

template <class T>
void HoanVi(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}


//Algorithms:

//Insertion Sort
void insertionSort(int a[], int n, long long& cmp) {
    for (int i = 1; ++cmp && i < n; i++) {
        int tempValue = a[i]; 
        int j = i;
        while (++cmp && j >= 1 && ++cmp && a[j - 1] > tempValue){ 
            a[j] = a[j - 1];
            j--;
        }
        a[j] = tempValue;
    }   
}

//Shell Sort
void shellSort(int a[], int n, long long& cmp) {
    for (int gap = n / 2; ++cmp && gap > 0; gap /= 2){
        for (int i = gap; ++cmp && i < n; i++){
            int tempValue = a[i];
            int j = i;
            while (++cmp && j >= gap && ++cmp && a[j - gap] > tempValue){
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = tempValue;
        }
    }
}

//Binary Insertion Sort
int binarySearchPosition(int a[], int item, int left, int right, long long& cmp) {
    if (++cmp && left >= right){
        return (++cmp && item > a[left]) ? (left + 1) : left;
    }
    int mid = (left + right) / 2;
    if (++cmp && item == a[mid]) {
        return mid + 1;
    }
    if (++cmp && item > a[mid]) 
        return binarySearchPosition(a, item, mid + 1, right, cmp);
    return binarySearchPosition(a, item, left, mid - 1, cmp);
}

void binaryInsertionSort(int a[], int n, long long& cmp) {
    for (int i = 1; ++cmp && i < n; i++) {
        int tempValue = a[i];
        int j = i;
        int pos = binarySearchPosition(a, tempValue, 0, j - 1, cmp);
        while (++cmp && j - 1 >= pos) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = tempValue;
    }
}

//Quick Sort
int partition(int arr[], int low, int high, long long& cmp) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; ++cmp && j <= high - 1; j++) {
        if (++cmp && arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(int arr[], int low, int high, long long& cmp) {
    if (++cmp && low < high) {
        int pi = partition(arr, low, high, cmp);
        quickSort(arr, low, pi - 1, cmp);
        quickSort(arr, pi + 1, high, cmp);
    }
}

//Merge Sort
void merge(int arr[], int left, int mid, int right, long long& cmp)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; ++cmp && i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; ++cmp && j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    while (++cmp && i < n1 && ++cmp && j < n2) {
        if (++cmp && L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (++cmp && i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (++cmp && j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void mergeSort(int arr[], int left, int right, long long& cmp)
{
    if (++cmp && left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, cmp);
    mergeSort(arr, mid + 1, right, cmp);
    merge(arr, left, mid, right, cmp);
}

//Bubble Sort
void BubbleSort(int a[], int n, long long &cmp) {
    for (int i = 0; ++cmp && i < n - 1; i++)
        for (int j = 0; ++cmp && j < n - i - 1; j++)
            if (++cmp && a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}


//Shaker Sort
void ShakerSort(int a[], int n, long long &cmp) {
    int left = 0, right = n - 1;
    while (++cmp && left < right) {
        for (int i = left; ++cmp && i < right; i++)
            if (++cmp && a[i] > a[i + 1])
                swap(a[i], a[i + 1]);
        right--;
        for (int i = right; ++cmp && i > left; i--)
            if (++cmp && a[i] < a[i - 1])
                swap(a[i], a[i - 1]);
        left++;
    }
}

//Radix Sort
int getMax(int a[], int n, long long &cmp) {
    int maxVal = a[0];
    for (int i = 1; ++cmp && i < n; i++)
        if (++cmp && a[i] > maxVal)
            maxVal = a[i];
    return maxVal;
}

void countingSortForRadix(int a[], int n, int exp, long long &cmp) {
    int* output, count[10] = {0};
    output = new int[n];
    for (int i = 0; ++cmp && i < n; i++)
        count[(a[i] / exp) % 10]++;
    for (int i = 1; ++cmp && i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; ++cmp && i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; ++cmp && i < n; i++)
        a[i] = output[i];
}

void RadixSort(int a[], int n, long long &cmp) {
    int maxVal = getMax(a, n, cmp);
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortForRadix(a, n, exp, cmp);
}

//Selection Sort
void selectionSort(int arr[], int size, long long &cmp) {
    for (int i = 0; ++cmp && i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; ++cmp && j < size; j++) {
            if (++cmp && arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

//Heap Sort
void heapify(int arr[], int n, int i, long long &cmp) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (++cmp && left < n && ++cmp && arr[left] > arr[largest])
            largest = left;

        if (++cmp && right < n && ++cmp && arr[right] > arr[largest])
            largest = right;

        if (++cmp && largest == i)
            break;

        swap(arr[i], arr[largest]);
        i = largest;
    }
}

void heapSort(int arr[], int n, long long &cmp) {
    for (int i = n / 2 - 1; ++cmp && i >= 0; i--)
        heapify(arr, n, i, cmp);

    for (int i = n - 1; ++cmp && i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, cmp);
    }
}

//Counting Sort
void countingSort(int arr[], int n, long long &cmp) {
    if (++cmp && n == 0) return;

    int minVal = arr[0], maxVal = arr[0];
    for (int i = 1; ++cmp && i < n; i++) {
        if (++cmp && arr[i] < minVal) minVal = arr[i];
        if (++cmp && arr[i] > maxVal) maxVal = arr[i];
    }

    int range = maxVal - minVal + 1;

    int *count = new int[range];
    for (int i = 0; ++cmp && i < range; i++)
        count[i] = 0;

    for (int i = 0; ++cmp && i < n; i++)
        count[arr[i] - minVal]++;

    for (int i = 1; ++cmp && i < range; i++)
        count[i] += count[i - 1];

    int *output = new int[n];
    for (int i = n - 1; ++cmp && i >= 0; i--) {
        int shifted = arr[i] - minVal;
        output[count[shifted] - 1] = arr[i];
        count[shifted]--;
    }

    for (int i = 0; ++cmp && i < n; i++)
        arr[i] = output[i];

    delete[] count;
    delete[] output;
}


//Command line arguments
void inputData(int *&a, int &n, string path) {
    ifstream fin(path);
    if(!fin.is_open()) {
        cout << "Cannot open this file!\n";
        return;
    }
    fin >> n;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        fin >> a[i];
    }
    fin.close();
}

void command1(char* argv[]) {
    string algorithm = argv[2];
    string inputFile = argv[3];
    string outputPara = argv[4];

    int n;
    int *a;
    inputData(a, n, inputFile);

    long long cmp = 0;
    
    clock_t start = clock();
    if (algorithm == "insertion-sort") {
        insertionSort(a, n, cmp);
    }
    else if (algorithm == "shell-sort") {
        shellSort(a, n, cmp);
    }
    else if (algorithm == "binary-insertion-sort") {
        binaryInsertionSort(a, n, cmp);
    }
    else if (algorithm == "quick-sort") {
        quickSort(a, 0, n - 1, cmp);
    }
    else if (algorithm == "merge-sort") {
        mergeSort(a, 0, n - 1, cmp);
    }
    else if (algorithm == "bubble-sort") {
        BubbleSort(a, n, cmp);
    }
    else if (algorithm == "shaker-sort") {
        ShakerSort(a, n, cmp);
    }
    else if (algorithm == "radix-sort") {
        RadixSort(a, n, cmp);
    }
    else if (algorithm == "selection-sort") {
        selectionSort(a, n, cmp);
    }
    else if (algorithm == "heap-sort") {
        heapSort(a, n, cmp);
    }
    else if (algorithm == "counting-sort") {
        countingSort(a, n, cmp);
    }
    else {
        cout << "Unknow algorithm name!\n";
        delete[] a;
        return;
    }
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "Algorithm: " << algorithm << endl;
    cout << "Input file: " << inputFile << endl;
    cout << "Input size: " << n << endl;
    cout << "-------------------------------" << endl;
    if (outputPara == "-time") {
        cout << "Running time: " << time_taken << endl;
    }
    else if (outputPara == "-comp") {
        cout << "Comparisions: " << cmp << endl;
    }
    else if (outputPara == "-both") {
        cout << "Running time: " << time_taken << endl;
        cout << "Comparisions: " << cmp << endl;
    }
    
    ofstream fout("output.txt");
    if(!fout.is_open()) {
        cout << "Cannot open this file!";
        return;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout.close();
    delete[] a;
}

void createInputFile(int a[], int n, string path) {
    ofstream fout(path);
    if(!fout.is_open()) {
        cout << "Cannot open this file!";
        return;
    }
    fout << n << endl;
    for(int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout.close();
}
void createData(int *&a, int n, string ipf, int dt) {
    a = new int[n];
    GenerateData(a, n, dt);
    createInputFile(a, n, ipf);
}

void command2(char* argv[]) {
    string algorithm = argv[2];
    int n = atoi(argv[3]);
    string inputOrder = argv[4];
    string outputPara = argv[5];

    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: ";

    int dt;
    if (inputOrder == "-rand") {
        dt = 0;
        cout << "Randomized\n";
    }
    else if (inputOrder == "-sorted") {
        dt = 1;
        cout << "Sorted\n";
    }
    else if (inputOrder == "-rev") {
        dt = 2;
        cout << "Reverse\n";
    }
    else if (inputOrder == "-nsorted") {
        dt = 3;
        cout << "Nearly sorted\n";
    }
    else {
        printf("Error: unknown data order!\n");
        return;
    }

    int *a;
    createData(a, n, "input_cmd2.txt", dt);
    long long cmp = 0;
    
    clock_t start = clock();
    if (algorithm == "insertion-sort") {
        insertionSort(a, n, cmp);
    }
    else if (algorithm == "shell-sort") {
        shellSort(a, n, cmp);
    }
    else if (algorithm == "binary-insertion-sort") {
        binaryInsertionSort(a, n, cmp);
    }
    else if (algorithm == "quick-sort") {
        quickSort(a, 0, n - 1, cmp);
    }
    else if (algorithm == "merge-sort") {
        mergeSort(a, 0, n - 1, cmp);
    }
    else if (algorithm == "bubble-sort") {
        BubbleSort(a, n, cmp);
    }
    else if (algorithm == "shaker-sort") {
        ShakerSort(a, n, cmp);
    }
    else if (algorithm == "radix-sort") {
        RadixSort(a, n, cmp);
    }
    else if (algorithm == "selection-sort") {
        selectionSort(a, n, cmp);
    }
    else if (algorithm == "heap-sort") {
        heapSort(a, n, cmp);
    }
    else if (algorithm == "counting-sort") {
        countingSort(a, n, cmp);
    }
    else {
        cout << "Unknow algorithm name!\n";
        delete[] a;
        return;
    }
    clock_t end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "-------------------------------" << endl;
    if (outputPara == "-time") {
        cout << "Running time: " << time_taken << endl;
    }
    else if (outputPara == "-comp") {
        cout << "Comparisions: " << cmp << endl;
    }
    else if (outputPara == "-both") {
        cout << "Running time: " << time_taken << endl;
        cout << "Comparisions: " << cmp << endl;
    }
    
    ofstream fout("output.txt");
    if(!fout.is_open()) {
        cout << "Cannot open this file!";
        return;
    }
    fout << n << endl;
    for (int i = 0; i < n; i++) {
        fout << a[i] << " ";
    }
    fout.close();
    delete[] a;
}

void command3(char* argv[]) {
    string algorithm = argv[2];
    int n = atoi(argv[3]);
    string outputPara = argv[4];

    cout << "Algorithm: " << algorithm << endl;
    cout << "Input size: " << n << endl;

    string inputFile[4];
    inputFile[0] = "input_1.txt";
    inputFile[1] = "input_2.txt";
    inputFile[2] = "input_3.txt";
    inputFile[3] = "input_4.txt";

    for (int i = 0; i < 4; i++) {
        int *a;
        createData(a, n, inputFile[i], i);

        long long cmp = 0;
        
        clock_t start = clock();
        if (algorithm == "insertion-sort") {
            insertionSort(a, n, cmp);
        }
        else if (algorithm == "shell-sort") {
            shellSort(a, n, cmp);
        }
        else if (algorithm == "binary-insertion-sort") {
            binaryInsertionSort(a, n, cmp);
        }
        else if (algorithm == "quick-sort") {
            quickSort(a, 0, n - 1, cmp);
        }
        else if (algorithm == "merge-sort") {
            mergeSort(a, 0, n - 1, cmp);
        }
        else if (algorithm == "bubble-sort") {
            BubbleSort(a, n, cmp);
        }
        else if (algorithm == "shaker-sort") {
            ShakerSort(a, n, cmp);
        }
        else if (algorithm == "radix-sort") {
            RadixSort(a, n, cmp);
        }
        else if (algorithm == "selection-sort") {
            selectionSort(a, n, cmp);
        }
        else if (algorithm == "heap-sort") {
            heapSort(a, n, cmp);
        }
        else if (algorithm == "counting-sort") {
            countingSort(a, n, cmp);
        }
        else {
            cout << "Unknow algorithm name!\n";
            delete[] a;
            return;
        }
        clock_t end = clock();

        double time_taken = double(end - start) / CLOCKS_PER_SEC;

        cout << "Input order: ";
        switch (i)
        {
        case 0:
            cout << "Randomized\n";
            break;
        case 1:
            cout << "Sorted\n";
            break;
        case 2:
            cout << "Reverse\n";
            break;
        case 3:
            cout << "Nearly Sorted\n";
            break;
        default:
            printf("Error: unknown data order!\n");
        }
        cout << "-------------------------------" << endl;
        if (outputPara == "-time") {
            cout << "Running time: " << time_taken << endl;
        }
        else if (outputPara == "-comp") {
            cout << "Comparisions: " << cmp << endl;
        }
        else if (outputPara == "-both") {
            cout << "Running time: " << time_taken << endl;
            cout << "Comparisions: " << cmp << endl;
        }
        cout << endl;
        
        delete[] a;
    }
}

void command4(char* argv[]) {
    string algorithm[] = {argv[2], argv[3]};
    string inputFile = argv[4];

    int n;
    int *a[2];
    inputData(a[0], n, inputFile);
    inputData(a[1], n, inputFile);

    long long cmp[2] = {0};
    double time_taken[2] = {0};
    
    for (int i = 0; i < 2; i++) {
        clock_t start = clock();
        if (algorithm[i] == "insertion-sort") {
            insertionSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "shell-sort") {
            shellSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "binary-insertion-sort") {
            binaryInsertionSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "quick-sort") {
            quickSort(a[i], 0, n - 1, cmp[i]);
        }
        else if (algorithm[i] == "merge-sort") {
            mergeSort(a[i], 0, n - 1, cmp[i]);
        }
        else if (algorithm[i] == "bubble-sort") {
            BubbleSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "shaker-sort") {
            ShakerSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "radix-sort") {
            RadixSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "selection-sort") {
            selectionSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "heap-sort") {
            heapSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "counting-sort") {
            countingSort(a[i], n, cmp[i]);
        }
        else {
            cout << "Unknow algorithm name!\n";
            return;
        }
        clock_t end = clock();

        time_taken[i] = double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "Algorithm: " << algorithm[0] << " | " << algorithm[1] << endl;
    cout << "Input file: " << inputFile << endl;
    cout << "Input size: " << n << endl;
    cout << "-------------------------------" << endl;
    cout << "Running time: " << time_taken[0] << " | " << time_taken[1] << endl;
    cout << "Comparisions: " << cmp[0] << " | " << cmp[1] << endl;
    
    ofstream fout("output.txt");
    if(!fout.is_open()) {
        cout << "Cannot open this file!";
        return;
    }
    fout << n << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            fout << a[i][j] << " ";
        }
        fout << endl;
    }
    fout.close();

    for(int i = 0; i < 2; i++) 
        delete[] a[i];
}

void command5(char* argv[]) {
    string algorithm[] = {argv[2], argv[3]};
    int n = atoi(argv[4]);
    string inputOrder = argv[5];

    cout << "Algorithm: " << algorithm[0] << " | " << algorithm[1] << endl;
    cout << "Input size: " << n << endl;
    cout << "Input order: ";

    int *a[2];
    int dt;
    if (inputOrder == "-rand") {
        dt = 0;
        cout << "Randomized\n";
    }
    else if (inputOrder == "-sorted") {
        dt = 1;
        cout << "Sorted\n";
    }
    else if (inputOrder == "-rev") {
        dt = 2;
        cout << "Reverse\n";
    }
    else if (inputOrder == "-nsorted") {
        dt = 3;
        cout << "Nearly sorted\n";
    }
    else {
        printf("Error: unknown data order!\n");
        return;
    }

    createData(a[0], n, "input.txt", dt);
    inputData(a[1], n, "input.txt");

    long long cmp[2] = {0};
    double time_taken[2] = {0};
    
    for (int i = 0; i < 2; i++) {
        clock_t start = clock();
        if (algorithm[i] == "insertion-sort") {
            insertionSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "shell-sort") {
            shellSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "binary-insertion-sort") {
            binaryInsertionSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "quick-sort") {
            quickSort(a[i], 0, n - 1, cmp[i]);
        }
        else if (algorithm[i] == "merge-sort") {
            mergeSort(a[i], 0, n - 1, cmp[i]);
        }
        else if (algorithm[i] == "bubble-sort") {
            BubbleSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "shaker-sort") {
            ShakerSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "radix-sort") {
            RadixSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "selection-sort") {
            selectionSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "heap-sort") {
            heapSort(a[i], n, cmp[i]);
        }
        else if (algorithm[i] == "counting-sort") {
            countingSort(a[i], n, cmp[i]);
        }
        else {
            cout << "Unknow algorithm name!\n";
            return;
        }
        clock_t end = clock();

        time_taken[i] = double(end - start) / CLOCKS_PER_SEC;
    }

    cout << "-------------------------------" << endl;
    cout << "Running time: " << time_taken[0] << " | " << time_taken[1] << endl;
    cout << "Comparisions: " << cmp[0] << " | " << cmp[1] << endl;

    for(int i = 0; i < 2; i++) 
        delete[] a[i];
}

int main(int argc, char* argv[]) {
    if (string(argv[1])  == "-a") {
        cout << "ALGORITHM MODE\n";
        if (argc == 5 && string(argv[3]) == "input.txt") {
            command1(argv);
        }
        else if (argc == 5 && string(argv[3]) != "input.txt") {
            command3(argv);
        }
        else if (argc == 6) {
            command2(argv);
        }
    }
    else if (string(argv[1])  == "-c") {
        if (argc == 5) {
            command4(argv);
        }
        else 
            command5(argv);
    }
    else {
        cout << "Unknow mode!";
        return 1;
    }
    
    return 0;
}