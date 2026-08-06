from abc import ABC, abstractmethod

class Payment(ABC):

    @abstractmethod
    def pay(self, amount):
        pass

class CreditCardPayment(Payment):

    def pay(self, amount):
        print(f"Payment made using Credit Card for amount ${amount}")

class PayPalPayment(Payment):

    def pay(self, amount):
        print(f"Payment made using PayPal for amount ${amount}")

class NormalPayment:

    def pay(self, amount):
        print(f"Payment made using Normal Payment for amount ${amount}")

def process_payment(payment: Payment, amount: float):
    payment.pay(amount)

# Example usage
credit_card_payment = CreditCardPayment()
paypal_payment = PayPalPayment()
normal_payment = NormalPayment()

process_payment(credit_card_payment, 100)
process_payment(paypal_payment, 200)
process_payment(normal_payment, 50)