#include <stdio.h>
#include <stdlib.h>

// Struktur node
typedef struct node {
  int data;
  struct node *next;
} Node;

// inisiasi node awal = NULL
Node *head = NULL;

// Menambahkan elemen awal
void push_front(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

// Menambahkan elemen akhir
void push_back(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_node;
  }
}

// Menghapus elemen awal
void pop_front() {
  if (head == NULL) {
    return;
  }

  Node *temp = head;
  head = head->next;
  free(temp);
}

// Menghapus elemen akhir
void pop_back() {
  if (head == NULL) {
    return;
  }

  Node *temp = head;
  Node *prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  if (prev == NULL) {
    head = NULL;
  } else {
    prev->next = NULL;
  }
  free(temp);
}

//mencari element tengah 
Node *get_middle() {
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

//menghapus element tengah
void pop_middle(Node *node)
{
    if (node == NULL || node == head)
    {
        return;
    }

    Node *prev = head;
    while (prev->next != node && prev->next != NULL)
    {
        prev = prev->next;
    }

    if (prev->next == NULL) 
    {
        return;
    }

    prev->next = node->next;
    free(node);
}

// Menambahkan element tengah
void push_middle(Node **head, int data) {
  Node *middle = get_middle(*head);
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = middle->next;
  middle->next = new_node;
}

// Mengecek linkedlist apakah kosong
int is_empty() {
  return head == NULL;
}

// Mencetak isi linked list
void print_list() {
  Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice, data;
  while (1) {
    printf("\n|----------Menu------------|");
    printf("\n|1. insert elemen ke awal  |");
    printf("\n|2. insert elemen ke akhir |");
    printf("\n|3. insert element tengah  |");
    printf("\n|4. Hapus elemen awal      |");
    printf("\n|5. Hapus elemen akhir     |");
    printf("\n|6. Hapus elemen tengah    |");
    printf("\n|7. Tampilkan linked list  |");
    printf("\n|8. Exit                   |");
    printf("\n|__________________________|");
    printf("\nMasukkan pilihan Anda: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Masukkan data untuk ditambahkan ke awal: ");
        scanf("%d", &data);
        push_front(data);
        break;
      case 2:
        printf("Masukkan data untuk ditambahkan ke akhir: ");
        scanf("%d", &data);
        push_back(data);
        break;
      case 3:
        printf("Masukkan data untuk ditambahkan ke tengah: ");
        scanf("%d", &data);
        push_middle(&head, data);
        break;
      case 4:
        pop_front();
        printf("Elemen pertama telah dihapus\n");
        break;
      case 5:
        pop_back();
        printf("Elemen terakhir telah dihapus\n");
        break;
      case 6:
        pop_middle(get_middle());
        printf("Elemen tengah telah dihapus\n");
        break;
      case 7:
        if (is_empty()) {
          printf("Linked list kosong\n");
        } else {
          printf("Tampilan linked list: ");
          print_list();
        }
        break;
      case 8:
        printf("Terimakasih telah menggunakan program saya\n");
        exit(0);
      default:
        printf("Pilihan salah! Silahkan coba lagi\n");
    }
  }

  return 0;
}
