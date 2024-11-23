#!/usr/bin/env python3
"""The module for date Manipulation"""
from datetime import datetime, timedelta


def add_12_hours(date_str):
    """
    Adds 12 hours to the given date string in EST.
    Args:
        date_str (str): Input date string
    Returns:
        str: Updated date string with 12 hours added, in the same format.
    """
    dt = datetime.strptime(date_str, "%Y-%m-%d %H:%M:%S EST")
    updated_dt = dt + timedelta(hours=12)
    return updated_dt.strftime("%Y-%m-%d %H:%M:%S EST")


input_date = "2024-11-23 08:30:00 EST"
result = add_12_hours(input_date)
print(f"Updated date: {result}")
