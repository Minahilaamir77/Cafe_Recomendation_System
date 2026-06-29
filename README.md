
Cafe Recommendation & Billing System
A console-based C++ application that filters menu items based on user preferences, manages a multi-item ordering cart, and processes dynamic tax calculations at checkout.

Features & User Options
The application guides the user through three distinct stages, offering specific interactive options at each step:

1. Menu Filtering Options
Before displaying the menu, the system prompts the user for their specific dining criteria to narrow down the choices:

Budget Input: Enter a maximum spending limit to filter out unaffordable items.

Dietary Preference: Select between Veg or Non-Veg options.

Spice Preference: Select between Spicy or Non-Spicy profiles.

2. Cart & Order Options
Once the tailored recommendations are displayed, the user can build their order:

Item Selection: Input specific item IDs from the filtered list to add them to the cart.

Quantity Selection: Specify the exact number of servings for each selected item.

Multi-Item Support: Add multiple distinct items to a single order before proceeding to checkout.

3. Payment & Billing Options
At checkout, the program processes the final transaction based on user choice:

Payment Method: Choose between Cash or Card.

Dynamic GST Application: The system automatically calculates tax based on the payment selection:

Cash: Applies a 16% GST rate.

Card: Applies a 5% GST rate.

Budget Verification: The system prints a formatted text receipt showing the subtotal, tax, and final total, explicitly flagging if the bill has exceeded the initial budget limit.
