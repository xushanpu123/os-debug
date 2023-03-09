import re
from pathlib import Path

import numpy as np
import pandas as pd

path = Path("output")
Nproc_per_case = 2500
file_name_re = re.compile(r"^output(\d*)-(\d*)\.txt$")
content_re = re.compile(r"^\[kernel\] Panicked at .*$", re.M)


def extract_result():
    arr = []
    for container in path.iterdir():
        for file in container.iterdir():
            file_name_result = file_name_re.match(file.name)
            container_id = int(file_name_result.group(1))
            proc_id = int(file_name_result.group(2))
            case_id = container_id * Nproc_per_case + proc_id - 1

            res_str = ""
            with open(file, "r", encoding="utf-8") as f:
                data = f.read()
                content_result = content_re.search(data)
                if content_result is None:
                    res_str = "succ"
                else:
                    res_str = content_result.group(0)

                res_array = [case_id, res_str]
                arr.append(res_array)

    array = np.array(arr)
    df = pd.DataFrame(array)
    df.to_excel("res.xlsx", index=False)


if __name__ == "__main__":
    extract_result()
