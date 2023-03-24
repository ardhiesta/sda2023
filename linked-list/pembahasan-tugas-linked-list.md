### 1. Membuat Linked List

Linked list dibuat menggunakan function create_ll()

```
struct node *create_ll()
{
    struct node *start = NULL;
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1)
    {
        new_node = (struct node*)malloc(sizeof(struct node));
                
        new_node->data = num;
        if(start == NULL)
        {            
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
                
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}
```

membuat node baru
```
new_node = (struct node*)malloc(sizeof(struct node));
```

ada pointer *start untuk menandai awal linked list

```
*start = NULL
misal node pertama diisi angka 2
new_node->data = num;
new_node->next = NULL;
|2|next : NULL|
start = new_node
```

tambah node baru, misal diisi angka 4

pointer *ptr untuk melakukan traversing ke node terakhir

ptr diarahkan ke start
```
ptr = start;
```

```
|2|next : NULL|
start 
ptr
```

traversing ke node terakhir 
```
while(ptr->next != NULL)
    ptr = ptr->next;
```

bikin node baru
```
new_node = (struct node*)malloc(sizeof(struct node));
```

next dari ptr diarahkan ke node baru
```
ptr->next = new_node;
```

data dari node baru diisi
```
new_node->data = num;
```
next dari node baru diarahkan ke NULL
```
new_node->next = NULL;
```

```
|2|next : new_node| --> |4|next: NULL|
start 
ptr
```

dan seterusnya untuk data-data selanjutnya
```
|2|next : 4| --> |4|next: new_node| --> |1|next: NULL|
start               ptr
```

```
|2|next : 4| --> |4|next: 1| --> |1|next: new_node| --> |6|next: NULL|
start                               ptr
```

### 2. Menambahkan node baru di awal linked list

digunakan fungsi insert_beg()

```
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}
```

pointer *start untuk menandai node awal, misal isi linked list di awal adalah sebagai berikut
```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                               ptr
```

buat node baru, misal data yang ditambahkan adalah 3
```
new_node = (struct node *)malloc(sizeof(struct node));
|3|next: NULL|
```

isi data node baru
```
new_node->data = num;
```

next dari node baru diarahkan ke start
```
new_node->next = start;
```

hasil
```
|3|next: start| --> |2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
                    start                               ptr
```

pointer start dipindah ke node yang baru diinput 
```
start = new_node;
```

hasil akhir :
```
|3|next: start| --> |2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                                                   ptr
```

### 3. Menambahkan node baru di akhir linked list

digunakan fungsi insert_end()

```
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    return start;
}
```

pointer *start untuk menandai node awal
```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                               ptr
```

buat node baru
```
new_node = (struct node *)malloc(sizeof(struct node));
```

isi data node baru
```
new_node->data = num;
```

next dari node baru diarahkan ke NULL
```
new_node->next = NULL;
```

misal data yang mau ditambahkan ke linked list adalah 3
```
|3|next: NULL|
```

pointer ptr dipindah ke start 
```
ptr = start;
```

hasil
```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start
ptr                               
```

traversing linked list
```
while(ptr->next != NULL)
    ptr = ptr->next;
```

ptr sampai di node terakhir
```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                                               ptr
```

node baru disambungkan di akhir linked list
```
ptr->next = new_node;
```

hasil akhir
```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: new_node| --> |3|next: NULL|
start                                               ptr
```

### 4. Menambahkan node baru sebelum node tertentu

fungsi yang digunakan adalah insert_before()

```
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while(ptr->data != val)
    {
        preptr = ptr;   
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}
```

buat node baru, input data yang masu dimasukkan ke node baru
```
new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = num;
```

misal node baru berisi 3
```
|3|next: NULL|
```

input data node yang mau diinsert node baru pada posisi sebelum data yang dimaksud

misal node baru diinsert sebelum node dengan data 1
```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                               ptr
```

pointer ptr diarahkan ke start
```
ptr = start;
```

```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                               
ptr
```

pointer preptr dipindah ke sebelum node yang dimaksud

pointer ptr dipindah ke node yang dimaksud

```
while(ptr->data != val)
{
    preptr = ptr;
    ptr = ptr->next;
}
```

```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start               preptr          ptr                    
```

next dari preptr dihubungkan ke node baru
```
preptr->next = new_node;
```

next dari node baru diarahkan ke ptr
```
new_node->next = ptr;
```

```
|2|next : 4| --> |4|next: 1| --> |3|next: 6| --> |1|next: 6| --> |6|next: NULL|
start               preptr                          ptr  
```

### 5. Menambahkan node baru setelah node tertentu

fungsi yang digunakan adalah insert_after()

```
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    preptr = ptr;
    while(preptr->data != val)
    {   
        preptr = ptr;         
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    return start;
}
```

buat node baru, input data yang masu dimasukkan ke node baru
```
new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = num;
```

misal node yang ditambahkan berisi value 3
```
|3|next: NULL|
```

input data node yang mau diinsert node baru pada posisi sebelum data yang dimaksud

misal node baru diinsert setelah node dengan data 1

```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                               ptr
```

pointer ptr diarahkan ke start
```
ptr = start;
```

pointer preptr diarahkan ke ptr 
```
preptr = ptr;
```

```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                               
ptr
preptr
```

pointer preptr dipindah ke node yang dimaksud

pointer ptr dipindah ke setelah node yang dimaksud

```
while(preptr->data != val)
{   
    preptr = ptr;         
    ptr = ptr->next;
}
```

```
|2|next : 4| --> |4|next: 1| --> |1|next: 6| --> |6|next: NULL|
start                               preptr          ptr                    
```

next dari preptr dihubungkan ke node baru
```
preptr->next = new_node;
```

next dari node baru diarahkan ke ptr
```
new_node->next = ptr;
```

hasil akhir
```
|2|next : 4| --> |4|next: 1| --> |1|next: 3| --> |3|next: ptr| --> |6|next: NULL|
start                               preptr                          ptr 
```