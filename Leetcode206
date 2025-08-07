import java.util.Scanner;

// Definition for singly-linked list node
class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

// Solution class with reverse method
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null) {
            ListNode next = curr.next; // Store next node
            curr.next = prev;          // Reverse current pointer
            prev = curr;               // Move prev one step forward
            curr = next;               // Move curr one step forward
        }

        return prev; // New head of reversed list
    }
}

// Main class to run the program
public class Main {
    // Utility method to create linked list from array
    public static ListNode createList(int[] values) {
        if (values.length == 0) return null;

        ListNode head = new ListNode(values[0]);
        ListNode current = head;

        for (int i = 1; i < values.length; i++) {
            current.next = new ListNode(values[i]);
            current = current.next;
        }

        return head;
    }

    // Utility method to print linked list
    public static void printList(ListNode head) {
        ListNode curr = head;
        while (curr != null) {
            System.out.print(curr.val);
            if (curr.next != null) System.out.print(" -> ");
            curr = curr.next;
        }
        System.out.println();
    }

    // Main method (entry point)
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Take input: size of list
        System.out.print("Enter number of elements in linked list: ");
        int n = scanner.nextInt();
        int[] values = new int[n];

        // Take list values
        System.out.print("Enter the values: ");
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }

        // Create list
        ListNode head = createList(values);

        // Print original list
        System.out.print("Original List: ");
        printList(head);

        // Reverse the list
        Solution solution = new Solution();
        ListNode reversedHead = solution.reverseList(head);

        // Print reversed list
        System.out.print("Reversed List: ");
        printList(reversedHead);

        scanner.close();
    }
}
