from random import randint,seed

def hash_func(msg):
    seed(msg)
    hash_val = randint(2,2**20)
    return hash_val

sender_msg = input("Enter the message to be sent: ")

sender_hash = hash_func(sender_msg)

print("\nMessage sent: " + sender_msg)
print("Hash value of the message sent: " + str(sender_hash))

receiver_msg = input("\nEnter the msg received: ")

receiver_hash = hash_func(receiver_msg)

print("\nMessage received: " + receiver_msg)
print("Hash value of the message received: " + str(receiver_hash))

if(sender_hash == receiver_hash):
    print("\nMessage is not modified - Integrity is achieved")
else:
    print("\nMessage is modified - Integrity is not achieved")
