#include <iostream>
#include <mysql.h>
#include <chrono>
#include <sstream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <map>
#include <conio.h>
#include <thread>
#include <tabulate/table.hpp>

using namespace std;
using namespace tabulate;
using Row_t = Table::Row_t;

int pilih,pilih1;
char escKey;



void Tampilan1(MYSQL *conn, const string &query) {
    string text
;    int query_state = mysql_query(conn, query.c_str());


    if (!query_state) {
        MYSQL_RES *result = mysql_store_result(conn);
        MYSQL_FIELD *field;
        MYSQL_ROW row;
  Table readme;
  readme.format().border_color(Color::cyan);
  readme.add_row(Row_t{" "});
readme[0].format().hide_border_bottom();
        readme.add_row(Row_t{text});
  readme[1].format().font_align(FontAlign::center).font_color(Color::cyan).hide_border_top();
   readme.add_row(Row_t{" "});
  readme[2]
      .format()
      .font_align(FontAlign::center)
      .font_style({FontStyle::underline, FontStyle::italic})
      .font_color(Color::white).hide_border_top();

        Table tampilan;
        int num_fields = mysql_num_fields(result);

        // gunakan deklarasi disini agar data sebelumnya tidak tersimpan
        // sehingga ketika swtich fitur tidak ada data yang sebelumnya
        Row_t header_row;
        for (int i = 0; i < num_fields; i++) {
            // data nama header
            field = mysql_fetch_field(result);
            header_row.push_back(field->name);
        }

        tampilan.add_row(header_row);

        // Format baris pertama (indeks 0)
        tampilan[0].format()
            .font_align(FontAlign::center)
            .font_color(Color::cyan)
            .font_style({FontStyle::bold});

        mysql_data_seek(result, 0);
        while ((row = mysql_fetch_row(result))) {
            // isi column (Header)
            Row_t data_row;
            for (int i = 0; i < num_fields; i++) {
                if (row[i] != nullptr) {
                    data_row.push_back(row[i]);
                } else {
                    data_row.push_back("NULL");
                }
            }
            tampilan.add_row(data_row);
        }
        readme.add_row(Row_t{tampilan});

        readme[3].format()
    .font_align(FontAlign::center);

//      for (auto& cell : readme.row(2)) {
//      cell.format()
//        .font_align(FontAlign::center)
//        .font_color({Color::cyan});
//
//  }

 //cout << tampilan;
      cout <<readme ;

        mysql_free_result(result);
    } else {
        cout << "Error in query execution: " << mysql_error(conn) << endl;
    }
}


void Tampilan(MYSQL *conn, const string &query, string text) {
    int query_state = mysql_query(conn, query.c_str());


    if (!query_state) {
        MYSQL_RES *result = mysql_store_result(conn);
        MYSQL_FIELD *field;
        MYSQL_ROW row;
  Table readme;
  readme.format().border_color(Color::cyan);
  readme.add_row(Row_t{" "});
readme[0].format().hide_border_bottom();
        readme.add_row(Row_t{text});
  readme[1].format().font_align(FontAlign::center).font_color(Color::cyan).hide_border_top();
   readme.add_row(Row_t{" "});
  readme[2]
      .format()
      .font_align(FontAlign::center)
      .font_style({FontStyle::underline, FontStyle::italic})
      .font_color(Color::white).hide_border_top();

        Table tampilan;
        int num_fields = mysql_num_fields(result);

        // gunakan deklarasi disini agar data sebelumnya tidak tersimpan
        // sehingga ketika swtich fitur tidak ada data yang sebelumnya
        Row_t header_row;
        for (int i = 0; i < num_fields; i++) {
            // data nama header
            field = mysql_fetch_field(result);
            header_row.push_back(field->name);
        }

        tampilan.add_row(header_row);

        // Format baris pertama (indeks 0)
        tampilan[0].format()
            .font_align(FontAlign::center)
            .font_color(Color::cyan)
            .font_style({FontStyle::bold});

        mysql_data_seek(result, 0);
        while ((row = mysql_fetch_row(result))) {
            // isi column (Header)
            Row_t data_row;
            for (int i = 0; i < num_fields; i++) {
                if (row[i] != nullptr) {
                    data_row.push_back(row[i]);
                } else {
                    data_row.push_back("NULL");
                }
            }
            tampilan.add_row(data_row);
        }
        readme.add_row(Row_t{tampilan});

        readme[3].format()
    .font_align(FontAlign::center);

//      for (auto& cell : readme.row(2)) {
//      cell.format()
//        .font_align(FontAlign::center)
//        .font_color({Color::cyan});
//
//  }

 //cout << tampilan;
      cout <<readme ;

        mysql_free_result(result);
    } else {
        cout << "\nTidak Ada Pilihan \ Query Error" << endl;
        cout <<"\nNotif [Error] Mysql Dialog : \n" << mysql_error(conn) << endl;
    }
}

//void Tampilan1(MYSQL *conn, const string &query) {
//    int query_state = mysql_query(conn, query.c_str());
//
//
//    if (!query_state) {
//        MYSQL_RES *result = mysql_store_result(conn);
//        MYSQL_FIELD *field;
//        MYSQL_ROW row;
//
//
//        int num_fields = mysql_num_fields(result);
//        vector<int> column_widths(num_fields, 0);
//
//        cout << endl<<endl;
//        // kalkulasi header colum berdasarkan lebar column
//        for (int i = 0; i < num_fields; i++) {
//            field = mysql_fetch_field(result);
//            int content_width = strlen(field->name);
//
//
//            mysql_data_seek(result, 0);
//            while ((row = mysql_fetch_row(result))) {
//                if (row[i] != nullptr) {
//                    int length = strlen(row[i]);
//                    if (length > content_width) {
//                        content_width = length;
//                    }
//                }
//            }
//
//            column_widths[i] = content_width; // Update column width
//            cout << setw(content_width + 2) << left << field->name;
//
//        }
//        cout << endl;
//
//        // Display separator line
//        for (int i = 0; i < accumulate(column_widths.begin(), column_widths.end(), 0) + 2 * (num_fields - 1); i++) {
//            cout << "=";
//        }
//        cout << endl;
//
//        // Display data
//        mysql_data_seek(result, 0); // Set row cursor to the beginning
//        while ((row = mysql_fetch_row(result))) {
//            for (int i = 0; i < num_fields; i++) {
//                if (row[i] != nullptr) {
//                  cout << setw(column_widths[i] + 2) << left << row[i];
//                  cout << left ;
//                } else {
//                    cout << setw(column_widths[i] + 2) << left << "NULL";
//                }
//            }
//            cout << endl;
//        }
//
//        mysql_free_result(result);
//    } else {
//        cout << "Error in query execution: " << mysql_error(conn) << endl;
//    }
//}






void Display_hewan(MYSQL* conn, int pilih) {

system("cls");
    if (conn) {
        cout << "Pilih(1 untuk Ascending, 2 untuk Descending): ";
        cin >> pilih;

        string orderType = (pilih == 1) ? "ASC" : ((pilih == 2) ? "DESC" : "Tidak Ada Pilihan" ) ;

        string query = "SELECT "
            "  h.Id_Hewan as \"Kode Hewan\","
            "  h.Nama,"
            "  h.NamaIlmiah,"
            "  h.Jenis_hewan as \"Jenis\","
            "  h.JenisKelamin as \"Jenis Kelamin\","
            "  h.Tgl_Lahir,"
            "  CONCAT(DATEDIFF(CURRENT_DATE, h.Tgl_Lahir), ' Hari') AS Umur_hari,"
            "  CONCAT(FLOOR(DATEDIFF(CURRENT_DATE, h.Tgl_Lahir) / 365), ' Tahun') AS Umur_Tahun "
            "FROM hewan h "
            "ORDER BY DATEDIFF(CURRENT_DATE, h.Tgl_Lahir) " + orderType;


            string text;
             if (pilih == 1){
                text ="Menampilkan Hewan Berdasarkan Usia/Umur [Ascending]";

             }else{
             text ="Menampilkan Hewan Berdasarkan Usia/Umur [Descending]";
             }

Tampilan(conn,query,text);
    } else {
        cout << "Failed to connect to database" << endl;
    }
}

void hewan_status(MYSQL *conn, int pilih) {
    system("cls");
    cout << "Pilih (1 untuk Sehat, 2 untuk Sakit): ";
    cin >> pilih;

    if (conn) {
        string statusFilter;
     if (pilih == 1) {
        statusFilter="Sehat";

     }  else if (pilih == 2){
          statusFilter = "Sakit";
     }else {
     cout << "Tidak Ada Pilihan";
     };
if (statusFilter=="Sehat" || statusFilter=="Sakit" ){
        // Query to retrieve animal health status
        string queryStatus = "SELECT "
            "  p.Id_Hewan AS \"Kode Hewan\","
            "  h.Nama AS Nama_Hewan,"
            "  Hasil_Pmk AS Status "
            "FROM "
            "  pemeriksaan p "
            "JOIN "
            "  hewan h ON p.Id_Hewan = h.Id_Hewan "
            "WHERE "
            "  p.Hasil_Pmk = '" + statusFilter + "';";

        // Query to count the number of sick animals
        string queryCount = "SELECT "
            "  COUNT(*) AS Jumlah_Hewan_Sakit "
            "FROM "
            "  pemeriksaan "
            "WHERE "
            "  Hasil_Pmk = '" + statusFilter + "';";

//         Tampilan1(conn,queryStatus,text);

            string text;
             if (pilih == 1){
                text ="Menampilkan Hewan Berdasarkan Status [Sehat] & Jumlah";

             }else{
             text ="Menampilkan Hewan Berdasarkan Status [Sakit] & Jumlah";
             }

    Tampilan(conn,queryStatus,text);

            int query_state = mysql_query(conn, queryCount.c_str());

            if (!query_state) {
                MYSQL_RES* countResult = mysql_store_result(conn);
                MYSQL_ROW countRow;

                cout << endl;
                if ((countRow = mysql_fetch_row(countResult))) {
                    cout << "Jumlah Hewan "<<statusFilter << ": "<< countRow[0] << endl;
                }

                mysql_free_result(countResult);
            } else {
                cout << "Error in query execution for counting sick animals: " << mysql_error(conn) << endl;
            }
}
    } else {
        cout << "Failed to connect to database" << endl;
    }
}

void kalkulasi_hewan(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT kb.Nama AS 'Nama Kebun Binatang', COUNT(*) AS 'Jumlah Hewan' "
                        "FROM hewan h "
                        "JOIN kebun_binatang kb ON h.Id_KebunBinatang = kb.Id_KebunBinatang "
                        "GROUP BY kb.Nama "
                        "ORDER BY kb.Nama;";

string text ;
text = "Total Jumlah Hewan yang Ada Pada Kebun Binatang";

    // Tampilkan hasil kueri menggunakan fungsi Tampilan1
    Tampilan(conn,query,text);

}



void jumlah_hewan(MYSQL *conn) {
    system("cls");

    if (conn) {
        // Query to retrieve the count of animals grouped by zoo
        string query = "SELECT kb.Nama AS \"Nama Kebun Binatang\", COUNT(*) AS \"  Jumlah Hewan\" "
            "FROM hewan h "
            "JOIN kebun_binatang kb ON h.Id_KebunBinatang = kb.Id_KebunBinatang "
            "GROUP BY kb.Nama "
            "ORDER BY kb.Nama;";
Tampilan(conn,query,"Menampilkan Jumlah Hewan");


    } else {
        cout << "Failed to connect to database" << endl;
    }
}

void huruf_hewan(MYSQL *conn) {
    char huruf;
    int pilihan;

    system("cls");
    cout << "Masukkan Huruf Nama Hewan: ";
    cin >> huruf;

    cout << "\nPilih Operasi yang Ingin Dijalankan:\n";
    cout << "1. Awalan\n";
    cout << "2. Tengah\n";
    cout << "3. Akhir\n";
    cout << "4. Dimanapun\n";
    cout << "Pilihan (1-4): ";
    cin >> pilihan;
if (pilihan == 1 || pilihan == 2 || pilihan == 3|| pilihan == 4){
    string query;
    switch (pilihan) {
        case 1:
            // Awalan: SELECT * FROM `hewan` WHERE Nama LIKE 'huruf%';
            query = "SELECT id_hewan,nama,Jenis_hewan As Jenis, JenisKelamin As Gender FROM `hewan` WHERE Nama LIKE '" + string(1, huruf) + "%';";
            break;
        case 2:
            // Tengah: SELECT * FROM `hewan` WHERE SUBSTRING(Nama, CHAR_LENGTH(Nama) / 2, 1) = 'huruf';
            query = "SELECT id_hewan,nama,Jenis_hewan As Jenis, JenisKelamin As Gender FROM `hewan` WHERE SUBSTRING(Nama, CHAR_LENGTH(Nama) / 2, 1) = '" + string(1, huruf) + "';";
            break;
        case 3:
            // Akhir: SELECT * FROM `hewan` WHERE Nama LIKE CONCAT('%', 'huruf', '%') AND Nama REGEXP '[0-9]$';
            query = "SELECT id_hewan,nama,Jenis_hewan As Jenis, JenisKelamin As Gender  FROM `hewan` WHERE Nama LIKE CONCAT('%', '" + string(1, huruf) + "', '%') AND Nama REGEXP '[0-9]$';";
            break;
        case 4:
            // Dimanapun: SELECT * FROM `hewan` WHERE Nama LIKE '%huruf%';
            query = "SELECT id_hewan,nama,Jenis_hewan As Jenis, JenisKelamin As Gender  FROM `hewan` WHERE Nama LIKE '%" + string(1, huruf) + "%';";
            break;
        default:
            cout << "Pilihan tidak valid.";
            return;
    }
  string text;
if (pilihan == 1){
text = "Mencari Hewan Berdasarkan Huruf [Awalan]";
}else if (pilihan ==2){
text = "Mencari Hewan Berdasarkan Huruf [Tengah]";
}else if (pilihan == 3){
text = "Mencari Hewan Berdasarkan Huruf [Akhir]";
}else if (pilihan == 4){
text = "Mencari Hewan Berdasarkan Huruf [Dimanapun]";
}
    // Display results for the selected query
    Tampilan(conn, query, text);
    }else {
    cout << "\nTidak Ada Pilihan";
    }
}




void hewan_nama(MYSQL *conn) {
    string cari;
    system("cls");
    cout << "Masukkan Nama Hewan yang dicari : ";
    cin >> cari;

    // Correctly concatenate the variable in the SQL query
    string query = "SELECT h.Nama AS \"Nama Hewan\", h.NamaIlmiah AS \"Nama Ilmiah\", h.Jenis_hewan AS \"Jenis\", "
                   "k.Nama AS Kandang, k.Luas AS Luas, k.Lokasi AS Lokasi, k.JenisHabitat AS \"Jenis Habitat\", "
                   "p.Hasil_Pmk AS \"Status\" "
                   "FROM hewan h "
                   "JOIN kandang k ON h.Id_Kandang = k.Id_Kandang "
                   "LEFT JOIN pemeriksaan p ON h.Id_Hewan = p.Id_Hewan "
                   "WHERE h.Nama = '" + cari + "';";
string text="Mencari Hewan dengan Nama";
    Tampilan(conn, query,text);
}


void pakan_hewan(MYSQL *conn) {
    system("cls");

    // SQL query to fetch information about animals and their corresponding type of food
    string query = "SELECT h.Id_Hewan AS \"Kode Hewan\", h.Nama, h.NamaIlmiah, "
                   "h.Jenis_hewan AS \"Jenis Hewan\", p.Jenis AS \"Jenis Pakan\" "
                   "FROM hewan h JOIN pakan p ON h.Id_pakan = p.Id_pakan;";

    // Display the results of the query
    Tampilan(conn, query, "Menampilkan Jenis Pakan Setiap Hewan");
}

void pegawai_Dokter(MYSQL *conn) {
    system("cls");

    const char *query = "SELECT "
                        "id_dokter AS 'Kode Dokter', "
                        "nama AS 'Nama Lengkap', "
                        "Email AS 'Email', "
                        "jenis_kelamin AS 'Jenis Kelamin', "
                        "Telepon AS 'Nomor Telepon', "
                        "spesialis AS 'Spesialis/Keahlian', "
                        "Gaji AS Gaji,"
                        "'Memeriksa & Menyembuhkan Hewan' AS 'Tugas' "
                        "FROM dokter_hewan;";

    Tampilan(conn, query,"Data Pegawai dan Tugas [Dokter Hewan]");
}


void pegawai_Pelatih(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT "
                        "Id_Pelatih AS 'Kode Pelatih', "
                        "Nama AS 'Nama Lengkap', "
                        "Email AS 'Email', "
                        "Jenis_Kelamin AS 'Jenis Kelamin', "
                        "Telepon AS 'Nomor Telepon', "
                        "Jabatan AS 'Jabatan', "
                        "Gaji AS Gaji,"
                        "'Melatih dan Mengelola Perilaku Hewan' AS 'Tugas' "
                        "FROM pelatih_hewan;";


    Tampilan(conn,query,"Data Pegawai dan Tugas [Pelatih Hewan]");
}

void pegawai_Zookeeper(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT "
                        "Id_zookeeper AS 'Kode Zookeeper', "
                        "Nama AS 'Nama Lengkap', "
                        "Email AS 'Email', "
                        "Jenis_kelamin AS 'Jenis Kelamin', "
                        "Telepon AS 'Nomor Telepon', "
                        "Jabatan AS 'Jabatan', "
                        "Gaji AS Gaji,"
                        "'Menyediakan Pakan & Menyiapkan Pertunjukan' AS 'Tugas' "
                        "FROM zookeeper;";


    Tampilan(conn,query,"Data Pegawai dan Tugas [Zookeeper]");
}


void Waktu_pertunjukan(MYSQL *conn){
    system("cls");
    const char *query = "SELECT Nama_Pertunjukan, Lokasi, Waktu_mulai , Waktu_Berakhir FROM `pertunjukan`;";
    Tampilan(conn, query,"Informasi Waktu Pertunjukan");
}

void Tanggungjawab_pertunjukan(MYSQL *conn){
    system("cls");
    const char *query = "SELECT "
                        "pertunjukan.Nama_Pertunjukan AS 'Nama Pertunjukan', "
                        "zookeeper.Nama AS 'Penanggung Jawab', "
                        "zookeeper.Jabatan AS 'Jabatan' "
                        "FROM pertunjukan "
                        "JOIN zookeeper ON pertunjukan.Id_zookeeper = zookeeper.Id_zookeeper;";
    Tampilan(conn, query, "Penanggung Jawab Pertunjukan");
}


void Notpesen_pengunjung(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT p.Nama, p.No_Tiket "
                        "FROM `pengunjung` p "
                        "WHERE p.No_Tiket NOT IN (SELECT DISTINCT No_Tiket FROM `pesanan`);";

    Tampilan(conn, query,"List Pengunjung yang Tidak Pernah Memesan");



    const char *countQuery = "SELECT COUNT(*) AS Total "
                             "FROM `pengunjung` p "
                             "WHERE p.No_Tiket NOT IN (SELECT DISTINCT No_Tiket FROM `pesanan`);";

cout << "\nTotal Pengunjung yang tidak memesan : \n";
Tampilan(conn, countQuery, "Total");
}

void Avg_durasi(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT CONCAT(AVG(TIMESTAMPDIFF(MINUTE, t.Masuk, t.Keluar)), ' Menit') AS Rata_Rata_Durasi "
                        "FROM pengunjung p "
                        "JOIN tempatparkir t ON p.Plat_Kendaraan = t.Plat_Kendaraan "
                        "WHERE p.Tgl_masuk IS NOT NULL AND t.Keluar IS NOT NULL;";

    Tampilan(conn, query, "Rata-rata Durasi Lama Pengunjung di Kebun Binatang");
}

void Avg_Hari(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT COUNT(*) AS 'Total Pengunjung', "
                        "COUNT(*) / COUNT(DISTINCT Tgl_masuk) AS 'Rata Rata Harian', "
                        "COUNT(DISTINCT Tgl_masuk) AS 'Jumlah Hari' "
                        "FROM pengunjung;";

    Tampilan(conn, query, "Rata-rata Pengujung yang Datang [Per Hari]");
}

void Avg_Bulan(MYSQL *conn) {
    system("cls");

    string query = "SELECT "
                        "COUNT(*) AS 'Total Pengunjung', "
                        "DATE_FORMAT(Tgl_masuk, '%m') AS 'Bulan', "
                        "YEAR(Tgl_masuk) AS 'Tahun', "
                        "COUNT(*) / COUNT(DISTINCT MONTH(Tgl_masuk)) AS 'Rata Rata Pengunjung per Bulan' "
                        "FROM pengunjung "
                        "WHERE Tgl_masuk IS NOT NULL "
                        "GROUP BY YEAR(Tgl_masuk), MONTH(Tgl_masuk)";

    Tampilan(conn, query,"Rata-rata Pengujung yang Datang [Per Bulan]");
}

void Avg_Tahun(MYSQL *conn) {
    system("cls");

    string query = "SELECT "
                        "COUNT(*) AS 'Total Pengunjung', "
                        "YEAR(Tgl_masuk) AS 'Tahun', "
                        "COUNT(*) / COUNT(DISTINCT YEAR(Tgl_masuk)) AS 'Rata Rata Pengunjung per Tahun' "
                        "FROM pengunjung "
                        "WHERE Tgl_masuk IS NOT NULL "
                        "GROUP BY YEAR(Tgl_masuk)";

    Tampilan(conn, query, "Rata-rata Pengujung yang Datang [Per Tahun]");
}


void Banyak_menu(MYSQL *conn) {
    system("cls");
    string query = "SELECT "
                        "k.Menu, "
                        "SUM(p.QTY) AS Jumlah_Pesanan "
                        "FROM pesanan p "
                        "JOIN kantin k ON p.Id_kantin = k.Id_Kantin "
                        "GROUP BY k.Menu "
                        "ORDER BY Jumlah_Pesanan DESC "
                        "LIMIT 1";
    Tampilan(conn, query, "Menu Paling Banyak Di Pesan");
}

void Sedikit_menu(MYSQL *conn) {
    system("cls");
    string query = "SELECT "
                        "k.Menu, "
                        "SUM(p.QTY) AS Jumlah_Pesanan "
                        "FROM pesanan p "
                        "JOIN kantin k ON p.Id_kantin = k.Id_Kantin "
                        "GROUP BY k.Menu "
                        "ORDER BY Jumlah_Pesanan ASC "
                        "LIMIT 1";
    Tampilan(conn, query, "Menu Paling Sedikit Di Pesan");
}



void Tidak_Parkir(MYSQL *conn) {
    string pmk,hsl_pmk;
    int masuk;
    system("cls");

    string query = "SELECT no_tiket, Nama, "
                        "(SELECT COUNT(*) FROM `pengunjung` AS subquery WHERE subquery.Plat_Kendaraan IS NULL) AS 'Total' "
                        "FROM `pengunjung`";

    Tampilan(conn, query, "Data dan Total  Pengunjung yang Tidak Parkir / Tidak Membawa Kendaraan");
}

void Hasil_pmk(MYSQL *conn) {
    system("cls");

    string query = "SELECT hewan.Nama AS Nama_Hewan, dokter_hewan.Nama AS Nama_Dokter, pemeriksaan.Hasil_Pmk, pemeriksaan.Tgl_Pemeriksaan "
                        "FROM pemeriksaan "
                        "JOIN hewan ON pemeriksaan.Id_Hewan = hewan.Id_Hewan "
                        "JOIN dokter_hewan ON pemeriksaan.Id_dokter = dokter_hewan.Id_dokter";

    Tampilan(conn, query, "Hasil Pemeriksaan Hewan");
}

void Update_pmk(MYSQL *conn) {
    system("cls");

    int masuk;
    string pmk, hsl_pmk;



    cout << endl;
    Tampilan(conn, "SELECT * FROM pemeriksaan", "List Hewan" );
    cout << endl;
     cout << "============================================================================\n";
        cout << "\nMasukkan Jumlah Hewan Yang sudah Diperiksa = ";
    cin >> masuk;

    for (int i = 0; i < masuk; i++) {
        cout << "\nMasukkan Kode Hewan [" << i + 1 << "] yang sudah diperiksa = ";
        cin >> pmk;
        cout << "\nMasukkan Hasil Pemeriksaan (Sehat/Sakit): ";
        cin >> hsl_pmk;

        string query = "UPDATE pemeriksaan SET Hasil_Pmk = '" + hsl_pmk + "' WHERE Id_Hewan = '" + pmk + "'";
        if (mysql_query(conn, query.c_str())) {
            cerr << "Error in query: " << mysql_error(conn) << endl;
            return;
        }

        cout << "Data berhasil diupdate!" << endl;
    }
    system("Cls");
    cout << endl;
    // Jika ingin menampilkan sesuatu setelah update
    Tampilan(conn, "SELECT * FROM pemeriksaan", "Hasil Update Pemeriksaan Hewan" );
}




string Tgl;

void Keuangan_Tgl(MYSQL *conn) {
    system("cls");

    cout << "\nMasukkan DD(Day) <hanya angka> = ";
    cin >> Tgl;

    string query = "SELECT "
                        "T1.Tahun, "
                        "T1.Bulan, "
                        "T1.Tanggal, "
                        "T1.`Jumlah Kendaraan`, "
                        "T1.`Total Pendapatan` AS `Pendapatan Parkir`, "
                        "T2.`Jumlah Menu Terjual`, "
                        "T2.`Total Pendapatan Kantin`, "
                        "T3.`Jumlah Pengunjung`, "
                        "T3.`Total Pendapatan Pengunjung` "
                        "FROM "
                        "(SELECT "
                        "YEAR(Masuk) AS Tahun, "
                        "MONTH(Masuk) AS Bulan, "
                        "DAY(Masuk) AS Tanggal, "
                        "COUNT(*) AS `Jumlah Kendaraan`, "
                        "SUM(TIMESTAMPDIFF(HOUR, Masuk, Keluar) * Harga_Parkir) AS `Total Pendapatan` "
                        "FROM tempatparkir "
                        "WHERE DAY(Masuk) = " + Tgl +
                        " GROUP BY Tahun, Bulan, Tanggal) AS T1 "
                        "LEFT JOIN "
                        "(SELECT "
                        "YEAR(Tgl_order) AS `Tahun`, "
                        "MONTH(Tgl_order) AS Bulan, "
                        "DAY(Tgl_order) AS Tanggal, "
                        "SUM(Qty) AS `Jumlah Menu Terjual`, "
                        "SUM(Total_Harga) AS `Total Pendapatan Kantin` "
                        "FROM pesanan "
                        "WHERE DAY(Tgl_order) = " + Tgl +
                        " GROUP BY Tahun, Bulan, Tanggal) AS T2 "
                        "ON T1.Tahun = T2.Tahun AND T1.Bulan = T2.Bulan AND T1.Tanggal = T2.Tanggal "
                        "LEFT JOIN "
                        "(SELECT "
                        "YEAR(Tgl_masuk) AS Tahun, "
                        "MONTH(Tgl_masuk) AS Bulan, "
                        "DAY(Tgl_masuk) AS Tanggal, "
                        "COUNT(*) AS `Jumlah Pengunjung`, "
                        "SUM(Transaksi_Tiket) AS `Total Pendapatan Pengunjung` "
                        "FROM pengunjung "
                        "WHERE DAY(Tgl_masuk) = " + Tgl +
                        " GROUP BY Tahun, Bulan, Tanggal) AS T3 "
                        "ON T1.Tahun = T3.Tahun AND T1.Bulan = T3.Bulan AND T1.Tanggal = T3.Tanggal";

    Tampilan(conn, query, "Pendapatan [Per Tanggal]");
}

void Keuangan_Bln(MYSQL *conn) {
    system("cls");

    cout << "\nMasukkan MM(Month) <hanya angka> = ";
    cin >> Tgl;

    string query = "SELECT "
                        "T1.Tahun, "
                        "T1.Bulan, "
                        "T1.`Jumlah Kendaraan`, "
                        "T1.`Total Pendapatan` AS `Pendapatan Parkir`, "
                        "T2.`Jumlah Menu Terjual`, "
                        "T2.`Total Pendapatan Kantin`, "
                        "T3.`Jumlah Pengunjung`, "
                        "T3.`Total Pendapatan Pengunjung` "
                        "FROM "
                        "(SELECT "
                        "YEAR(Masuk) AS Tahun, "
                        "MONTH(Masuk) AS Bulan, "
                        "COUNT(*) AS `Jumlah Kendaraan`, "
                        "SUM(TIMESTAMPDIFF(HOUR, Masuk, Keluar) * Harga_Parkir) AS `Total Pendapatan` "
                        "FROM tempatparkir "
                        "WHERE MONTH(Masuk) = " + Tgl +
                        " GROUP BY Tahun, Bulan) AS T1 "
                        "LEFT JOIN "
                        "(SELECT "
                        "YEAR(Tgl_order) AS `Tahun`, "
                        "MONTH(Tgl_order) AS Bulan, "
                        "SUM(Qty) AS `Jumlah Menu Terjual`, "
                        "SUM(Total_Harga) AS `Total Pendapatan Kantin` "
                        "FROM pesanan "
                        "GROUP BY Tahun, Bulan) AS T2 "
                        "ON T1.Tahun = T2.Tahun AND T1.Bulan = T2.Bulan "
                        "LEFT JOIN "
                        "(SELECT "
                        "YEAR(Tgl_masuk) AS Tahun, "
                        "MONTH(Tgl_masuk) AS Bulan, "
                        "COUNT(*) AS `Jumlah Pengunjung`, "
                        "SUM(Transaksi_Tiket) AS `Total Pendapatan Pengunjung` "
                        "FROM pengunjung "
                        "GROUP BY Tahun, Bulan) AS T3 "
                        "ON T1.Tahun = T3.Tahun AND T1.Bulan = T3.Bulan";

    Tampilan(conn, query, "Pendapatan [Per Bulan]");
}

void Keuangan_Tahun(MYSQL *conn) {
    system("cls");
    cout << "\nMasukkan YY(Year) <hanya angka> = ";
    cin >> Tgl;

    // Query SQL untuk menghitung keuangan per tahun
    string query = "SELECT "
                   "T1.Tahun, "
                   "T1.`Jumlah Kendaraan`, "
                   "T1.`Total Pendapatan` AS `Pendapatan Parkir`, "
                   "T2.`Jumlah Menu Terjual`, "
                   "T2.`Total Pendapatan Kantin`, "
                   "T3.`Jumlah Pengunjung`, "
                   "T3.`Total Pendapatan Pengunjung` "
                   "FROM "
                   "(SELECT "
                   "YEAR(Masuk) AS Tahun, "
                   "COUNT(*) AS `Jumlah Kendaraan`, "
                   "SUM(TIMESTAMPDIFF(HOUR, Masuk, Keluar) * Harga_Parkir) AS `Total Pendapatan` "
                   "FROM tempatparkir "
                   "WHERE YEAR(Masuk) = " + Tgl +
                   " GROUP BY Tahun) AS T1 "
                   "LEFT JOIN "
                   "(SELECT "
                   "YEAR(Tgl_order) AS `Tahun`, "
                   "SUM(Qty) AS `Jumlah Menu Terjual`, "
                   "SUM(Total_Harga) AS `Total Pendapatan Kantin` "
                   "FROM pesanan "
                   "WHERE YEAR(Tgl_order) = " + Tgl +
                   " GROUP BY Tahun) AS T2 "
                   "ON T1.Tahun = T2.Tahun "
                   "LEFT JOIN "
                   "(SELECT "
                   "YEAR(Tgl_masuk) AS Tahun, "
                   "COUNT(*) AS `Jumlah Pengunjung`, "
                   "SUM(Transaksi_Tiket) AS `Total Pendapatan Pengunjung` "
                   "FROM pengunjung "
                   "WHERE YEAR(Tgl_masuk) = " + Tgl +
                   " GROUP BY Tahun) AS T3 "
                   "ON T1.Tahun = T3.Tahun";

    // Panggil fungsi Tampilan1 dengan parameter query
    Tampilan(conn, query, "Pendapatan [Per Tahun]");
}

double AmbilTotal(MYSQL *conn, const string &query) {
    MYSQL_RES *result;
    MYSQL_ROW row;

    if (mysql_query(conn, query.c_str())) {
        cerr << "Error in AmbilTotal: " << mysql_error(conn) << endl;
        return 0.0;
    }

    result = mysql_store_result(conn);

    if (result == nullptr) {
        cerr << "Error in AmbilTotal: " << mysql_error(conn) << endl;
        return 0.0;
    }

    row = mysql_fetch_row(result);

    if (row == nullptr || row[0] == nullptr) {
        cerr << "Error in AmbilTotal: Result is NULL or value is NULL" << endl;
        mysql_free_result(result);
        return 0.0;
    }

    // Konversi nilai dari string ke double
    double total = stod(row[0]);

    mysql_free_result(result);

    return total;
}
void Keuangan_keseluruhan(MYSQL *conn) {
    system("cls");

    // Pendapatan Tempat Parkir
    string query1 = "SELECT SUM(TIMESTAMPDIFF(HOUR, Masuk, Keluar) * Harga_Parkir)AS 'Total Pendapatan Parkir' FROM tempatparkir";
  //  cout << "\nPendapatan Tempat Parkir :\n";
  cout << "\e[46m [XX] Pendapatan [Keseluruhan] [XX] \e[0m \n\n";
    Tampilan(conn, query1,"Pendapatan Tempat Parkir" );
    double totalParkir = AmbilTotal(conn, query1);

    // Pendapatan Kantin
    string query2 = "SELECT SUM(Total_Harga) AS 'Total Pendapatan Kantin' FROM pesanan";
   // cout << "\nPendapatan Kantin :\n";
   cout << endl;
    Tampilan(conn, query2,"Pendapatan Kantin");
    double totalKantin = AmbilTotal(conn, query2);

    // Pendapatan Keseluruhan
    string query3 = "SELECT SUM(Transaksi_Tiket) AS 'Total Pendapatan Pengunjung' FROM pengunjung";
  //  cout << "\nPendapatan Pengunjung :\n";
   cout << endl;
    Tampilan(conn, query3, "Pendapatan Pengunjung");
    double totalPengunjung = AmbilTotal(conn, query3);

     double totalKeseluruhan = totalParkir + totalKantin + totalPengunjung;
cout << fixed << setprecision(0) << "\nTotal Pendapatan Pengunjung, Kantin, dan Tempat Parkir = RP." << put_money(totalKeseluruhan) << endl;


}


void Pelatihan(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT "
                        "hewan.Nama AS Nama_Hewan, "
                        "pelatih_hewan.Nama AS Nama_Pelatih, "
                        "melatih.Tgl_Pelatihan AS Tanggal "
                        "FROM "
                        "melatih "
                        "JOIN "
                        "hewan ON melatih.Id_Hewan = hewan.Id_Hewan "
                        "JOIN "
                        "pelatih_hewan ON melatih.Id_Pelatih = pelatih_hewan.Id_Pelatih;";

    Tampilan(conn, query,"Menampilkan Hewan yang Di Latih");
}


void Lokasi(MYSQL *conn) {
    system("cls");
     cout << "Pilih(1 untuk Ascending, 2 untuk Descending): ";
        cin >> pilih;
     string orderType = (pilih == 1) ? "ASC" : ((pilih == 2) ? "DESC" : "Tidak Ada Pilihan" ) ;
string query = "SELECT "
                "kandang.Lokasi AS 'Lokasi Kandang', "
                "GROUP_CONCAT(hewan.Nama ORDER BY hewan.Nama ASC) AS Hewan "
                "FROM kandang "
                "LEFT JOIN hewan ON kandang.Id_Kandang = hewan.Id_Kandang "
                "GROUP BY kandang.Lokasi "
                "ORDER BY kandang.Lokasi " + orderType + ";";

    string text;
    if (pilih == 1){
     text ="Mengelompokan Hewan Berdasarkan Lokasi [Ascending]";
    }else{
     text ="Mengelompokan Hewan Berdasarkan Lokasi [Descending]";
    }

    Tampilan(conn, query, text);

}

void Info_luas(MYSQL *conn) {
    system("cls");
    const char *query = "SELECT "
                        "'Bandung Park Zoo' AS 'Nama Kebun Binatang', "
                        "SUM(Luas) AS Total_Luas "
                        "FROM kandang;";
    Tampilan(conn, query, "Informasi Luas Bandung Park Zoo");
}



void Header (){
cout << "\t\e[1;32m**Menu**\e[0m\n";
    cout << "\t\e[1;33m        __  __                                                   _        \e[0m" << endl;
    cout << "\t\e[1;33m       |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_      \e[0m" << endl;
    cout << "\t\e[1;33m       | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|     \e[0m" << endl;
    cout << "\t\e[1;33m    _ _| |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_      \e[0m" << endl;
    cout << "\t\e[1;33m   (_|_)_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|     \e[0m" << endl;
    cout << "\t\e[1;33m                                 |___/                                   \e[0m" << endl;
    cout << "\t\e[1;33m    _  __    _                   ____  _             _                    \e[0m" << endl;
    cout << "\t\e[1;33m   | |/ /___| |__  _   _ _ __   | __ )(_)_ __   __ _| |_ __ _ _ __   __ _ \e[0m" << endl;
    cout << "\t\e[1;33m   | ' // _ \\ '_ \\| | | | '_ \\  |  _ \\| | '_ \\ / _` | __/ _` | '_ \\ / _` |\e[0m" << endl;
    cout << "\t\e[1;33m   | . \\  __/ |_) | |_| | | | | | |_) | | | | | (_| | || (_| | | | | (_| |\e[0m" << endl;
    cout <<("\t\e[1;33m   |_||_\\___|_.__/ \\__,_|_| |_| |____/|_|_| |_|\\__,_|\\__\\__,_|_| |_|\\__, |\e[0m") << endl;
    cout <<("\t\e[1;33m                                                                    |___/ \e[0m") << endl;
    cout <<("\t\e[1;32m               >>--> Selamat datang di Bandung Park Zoo <--<<     \e[0m") << endl;


}


int printMenu2(int selectedOption) {
    char key;
    do {
        system("cls");
        Header(); // Assuming you have a function named 'Header()' for displaying a header
        cout << "\n\e[1;97m\e[46m [::] Silahkan Pilih Menu [::]\e[0m\n";
        cout << (selectedOption == 1 ? "\n [::] " : "\n [  ] ") << "Manajemen Hewan";
        cout << (selectedOption == 2 ? "\n [::] " : "\n [  ] ") << "Manajemen Pegawai";
        cout << (selectedOption == 3 ? "\n [::] " : "\n [  ] ") << "Manajemen Pertunjukkan";
        cout << (selectedOption == 4 ? "\n [::] " : "\n [  ] ") << "Manajemen Pakan";
        cout << (selectedOption == 5 ? "\n [::] " : "\n [  ] ") << "Manajemen Pengunjung";
        cout << (selectedOption == 6 ? "\n [::] " : "\n [  ] ") << "Manajemen Kantin";
        cout << (selectedOption == 7 ? "\n [::] " : "\n [  ] ") << "Manajemen Tempat Parkir";
        cout << (selectedOption == 8 ? "\n [::] " : "\n [  ] ") << "Manajemen Pemeriksaan";
        cout << (selectedOption == 9 ? "\n [::] " : "\n [  ] ") << "Manajemen Keuangan";
        cout << (selectedOption == 10 ? "\n [::] " : "\n [  ] ") << "Manajemen Pelatihan";
        cout << (selectedOption == 11 ? "\n [::] " : "\n [  ] ") << "Manajemen Kandang";
        cout << (selectedOption == 12 ? "\n [::] " : "\n [  ] ") << "Exit";

        key = _getch();
        switch (key) {
            case 72: // Up arrow key
                selectedOption = (selectedOption > 1) ? selectedOption - 1 : 12;
                break;
            case 80: // Down arrow key
                selectedOption = (selectedOption < 12) ? selectedOption + 1 : 1;
                break;
        }
    } while (key != 13);

    return selectedOption;  // Return the selected option after Enter is pressed
}

int main() {

    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "Bandung_park_zoo", 0, NULL, 0);
if(conn){

s1:
 pilih=printMenu2(1);

        switch (pilih) {
            case 1:

        system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Hewan";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout << "1.Menampilkan Hewan + ASC/DSC Umur \n2.Menampilkan Hewan Berdasarkan Status + Jumlah\n3.Menampilkan jumlah hewan\n4.Mencari Hewan dengan Nama\n5.Mencari Hewan Berdasarkan Huruf\n6.kalkulasi total jumlah hewan yang ada pada kebun binatang";
            cout << "\nPilih : ";
            cin >> pilih1;

        while (true){
if (pilih1==1){

    Display_hewan(conn,pilih1);


}else if(pilih1 ==2){
    hewan_status(conn,pilih1);
}else if(pilih1 ==3){
jumlah_hewan(conn);
}else if(pilih1 ==4){

hewan_nama(conn);
}else if(pilih1 ==5){
huruf_hewan(conn);

}else if(pilih1 ==6){
kalkulasi_hewan(conn);
}
                            cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            cout << "\n== Tekan [F5] untuk Refresh ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }

            escKey = _getch();
            if (escKey == 27) {
                // Handle going back to menu
                continue;
            }
        }
                break;
            case 2:
                system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Pegawai";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout << "\n1.Menampilkan data pegawai dan tugas mereka [Dokter Hewan] \n2.Menampilkan data pegawai dan tugas mereka [Pelatih Hewan]\n3.Menampilkan data pegawai dan tugas mereka [Zookeeper]";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1)
            {
                pegawai_Dokter(conn);

            }
            else if(pilih1 ==2)
            {
                pegawai_Pelatih(conn);
            }
            else if(pilih1 ==3)
            {
                pegawai_Zookeeper(conn);
            }
            else
            {
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }
                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }

                break;
            case 3:
             system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Pertunjukan";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout << "\n1.Menampilkan informasi waktu pertunjukan \n2.Menampilkan Penanggung Jawab Pertunjukan";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1)
            {
            Waktu_pertunjukan(conn);

            }
            else if(pilih1 ==2)
            {
          Tanggungjawab_pertunjukan(conn);
            }
            else
            {
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }
                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 4:
               system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Pakan";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout << "\n1.Menampilkan Jenis Pakan Setiap Hewan ";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1)
            {
            pakan_hewan(conn);

            }
            else
            {
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }
                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }

                break;
            case 5:
                               system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Pengujung";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout <<"\n1.Menampilkan Pengunjung yang tidak pernah memesan + Total\n"
                 <<"2.Rata-rata Durasi lama Pengunjung di Kebun Binatang"
                 <<"\n3.Rata-rata Pengujung yang Datang [Per Hari]"
                 <<"\n4.Rata-rata Pengujung yang Datang [Per Bulan]"
                 <<"\n5.Rata-rata Pengujung yang Datang [Per Tahun]";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1){
            Notpesen_pengunjung(conn);
            }else if (pilih1==2){
            Avg_durasi(conn);
            }else if (pilih1==3){
            Avg_Hari(conn);
            }else if (pilih1==4){
            Avg_Bulan(conn);
            }else if (pilih1==5){
            Avg_Tahun(conn);
            }else{
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }



                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 6:
            system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Kantin";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout <<"\n1.Menampilkan Menu Paling Banyak Di Pesan\n"
                 <<"2.Menampilkan Menu Paling Sedikit Di Pesan";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1){
            Banyak_menu(conn);
            }else if (pilih1==2){
            Sedikit_menu(conn);
            }else{
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }



                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 7:
            system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Tempat Parkir";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout <<"\n1.Menampilkan data dan total  Pengunjung (tidak parkir)\n";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1){
            Tidak_Parkir(conn);
            }else{
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }



                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 8:
                           system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Pemeriksaan";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout <<"\n1.Menampilkan Hasil Pemeriksaan Hewan\n2.Update Pemeriksaan Hewan";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1){
            Hasil_pmk(conn);
            }else if(pilih1==2){
            Update_pmk(conn);
            }else{
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }



                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 9:
            system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Keuangan";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout <<"\n1.Menghitung Pendapatan [Per Tanggal]\n2.Menghitung Pendapatan [Per Bulan]"
                 <<"\n3.Menghitung Pendapatan [Per Tahun]\n4.Menghitung Pendapatan [Keseluruhan]"
                 << "\n\e[46mNote :\e[0m\nPendapatan dari Pengunjung, Kantin, Tempat Parkir";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1){
           Keuangan_Tgl(conn);

            }else if(pilih1==2){
            Keuangan_Bln(conn);
            }else if(pilih1==3){
           Keuangan_Tahun(conn);
            }else if(pilih1==4){
            Keuangan_keseluruhan(conn);
            }else{
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }



                         cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 10:
           system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Pelatihan";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout <<"\n1.Menampilkan Hewan yang di Latih";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1){
           Pelatihan(conn);
            }else{
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }

             cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 11:
             system("cls");
            cout << "\n=================================================";
            cout << "\n\t   Manajemen Kandang";
            cout << "\n=================================================";
            cout << "\n\e[1;37m\033[48;5;212m[::] Silahkan Pilih Menu [::]\e[0m\n";
            cout <<"\n1.Mengelompokan Hewan Berdasarkan Lokasi Asc/Dsc\n"
                 <<"2.Informasi Luas Bandung Park Zoo";
            cout << "\nPilih : ";
            cin >> pilih1;
            if (pilih1==1){
            Lokasi(conn);
            }else if(pilih1==2){
            Info_luas(conn);
            }else{
                cout <<"\nTidak ada pilihan " << pilih1 << endl;
                system("pause");
                system("cls");
                goto s1;
            }

             cout << "\n== Tekan [ESC] untuk Kembali ke[menu] ==\n";
                            escKey = _getch();
                            if (escKey == 27)
                            {
                                // Handle going back to menu 2
                                system("cls");
                                goto s1;

                            }
                break;
            case 12:
                system("cls");
                cout << "\n\e[45mKeluar Dari Program\e[0m\nTerimakasih Telah menggunakan Program Management Kebun Binatang :v";
                Sleep(1000);
                system("curl parrot.live");
                return 0;
                break;
            default:
                // Handle invalid option (if needed)
                break;
        }
            // Menunggu input F5 untuk refresh


////batass
    }else{
        cout << "Tidak Terhubung ke Database";
    }

    return 0;
}


