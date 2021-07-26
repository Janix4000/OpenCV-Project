import os
from os.path import join, dirname, realpath
from time import strftime
import os

# Check if Windows or Linux
if os.name == 'nt':  # Windows
    BASE_PATH = 'C:\\'
else:
    BASE_PATH = '/working/'


STORAGE = join(BASE_PATH, "STORAGE")
CSV_FOLDER = join(STORAGE, "CSV")
INFLUX_STORAGE_PATH = join(STORAGE, 'CSV')
HDC1080_REPORTS_XLSX = join(STORAGE, 'HDC_Report')
PICKLE_DUMP = join(STORAGE, "PickleDump")

INFLUX_INSTALLATION_ID_DATA_PROCESSED = join(CSV_FOLDER, 'InstallationsDataProcessed')
INFLUX_INSTALLATION_ID_DATA_PROCESSED_INTERVALS = join(CSV_FOLDER, 'InstallationsDataProcessedIntervals')
INFLUX_INSTALLATION_ID_DATA_HISTOGRAMS = join(CSV_FOLDER, 'InstallationsDataHistograms')
INFLUX_INSTALLATION_ID_DATA_BASIC_ANALYSIS = join(CSV_FOLDER, 'InstallationsDataBasicAnalysis')

INFLUX_INSTALLATION_ID_DATA = join(INFLUX_STORAGE_PATH, 'InstallationsData')
INFLUX_INSTALLATION_ID_DATA_HISTOGRAMS_PLOTS = join(CSV_FOLDER, 'InstallationsDataHistogramsPlots')
INFLUX_INSTALLATION_ID_SIGNAL_DATA_HISTOGRAMS_PLOTS = join(CSV_FOLDER, 'InstallationsSignalDataHistogramsPlots')

# installation_data_path = CSV_FOLDER
# processed_installation_data_path = CSV_FOLDER + "//processed//"
# statistics_data_path = CSV_FOLDER + "//statistics//"
# health_data_path = CSV_FOLDER + "//health//"


INSTALLATIONS_DATA = join(CSV_FOLDER, 'InstallationsData')

INSTALLATION_DATA_PATH = CSV_FOLDER
PROCESSED_INSTALLATION_DATA_PATH = join(CSV_FOLDER, "processed")
STATISTICS_DATA_PATH = join(CSV_FOLDER, "statistics")
HEALTH_DATA_PATH = join(CSV_FOLDER, "health")

DIAGNOSTICS_DATA_PATH = join(CSV_FOLDER, 'DiagnosticsData')

LOCAL_GAS_MEASUREMENTS_DATA = join(CSV_FOLDER, 'local_measurements_data')

DIAGNOSTIC_REPORTS_XLSX = join(CSV_FOLDER, 'ResetReportXLSX')
DIAGNOSTIC_REPORTS_CSV = join(CSV_FOLDER, 'ResetReportCSV')
